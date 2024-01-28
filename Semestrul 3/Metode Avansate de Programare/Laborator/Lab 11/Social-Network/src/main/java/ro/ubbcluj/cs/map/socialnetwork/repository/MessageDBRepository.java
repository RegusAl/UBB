package ro.ubbcluj.cs.map.socialnetwork.repository;


import ro.ubbcluj.cs.map.socialnetwork.domain.Message;
import ro.ubbcluj.cs.map.socialnetwork.domain.User;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.*;

import static java.sql.DriverManager.getConnection;

public class MessageDBRepository implements MessagePagingRepository<Long, Message> {

    private final String url;
    private final String user;
    private final String password;
    private Repository<Long, User> userRepo;

    public MessageDBRepository(String url, String user, String password, Repository<Long, User> userRepo) {
        this.url = url;
        this.user = user;
        this.password = password;
        this.userRepo = userRepo;
    }

    /*
     * Find the main information about a message( id, from, text, date) from the messages table
     * - without using message-recipients - it might get into a loop because of the reply
     */
    public Optional<Message> findMessage(Long id) {
        String sql = "SELECT messages.* FROM messages WHERE messages.id = ?";

        try (Connection connection = getConnection(url, user, password);
             PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setLong(1, id);

            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                if (resultSet.next()) {
                    User fromUser = userRepo.findOne(resultSet.getLong("from_user_id")).get();
                    String messageText = resultSet.getString("message_text");
                    LocalDateTime dateTime = resultSet.getTimestamp("date_time").toLocalDateTime();
                    return Optional.of(new Message(id, fromUser, messageText, dateTime));
                }
            }
        } catch (SQLException e) {
            e.printStackTrace(); // Handle or log the exception based on your application's needs
        }

        return Optional.empty();
    }

    @Override
    public Optional<Message> findOne(Long longID) {
        String sql = "SELECT messages.*, message_recipients.to_user_id, message_recipients.reply_to_message_id " +
                "FROM messages " +
                "LEFT JOIN message_recipients ON messages.id = message_recipients.message_id " +
                "WHERE messages.id = ?";

        try (Connection connection = getConnection(url, user, password);
             PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setLong(1, longID);

            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                if (resultSet.next()) {
                    Message message = mapResultSetToMessage(resultSet);
                    return Optional.of(message);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace(); // Handle or log the exception based on your application's needs
        }

        return Optional.empty();
    }

    private Message mapResultSetToMessage(ResultSet resultSet) throws SQLException {
        Long messageId = resultSet.getLong("id");
        User fromUser = userRepo.findOne(resultSet.getLong("from_user_id")).get();
        String messageText = resultSet.getString("message_text");
        Timestamp dateTime = resultSet.getTimestamp("date_time");
        Message replyToMessageId = null;
        try {
            long replyToMessageIdValue = resultSet.getLong("reply_to_message_id");
            if (!resultSet.wasNull()) {
                replyToMessageId = findMessage(replyToMessageIdValue).get();
            }
        } catch (Exception e) {
            String error = e.getMessage();
        }

        // Extract the receiver information
        List<User> toUsers = new ArrayList<>();
        do {
            long toUserId = resultSet.getLong("to_user_id");
            if (toUserId != 0) {
                toUsers.add(userRepo.findOne(toUserId).get());
            }
        } while (resultSet.next());

        // Create and return a Message object
        return new Message(messageId, fromUser, toUsers, dateTime.toLocalDateTime(), messageText, replyToMessageId);
    }


    @Override
    public Iterable<Message> findAll() {
        String sql = "SELECT messages.*, message_recipients.to_user_id " +
                "FROM messages " +
                "LEFT JOIN message_recipients ON messages.id = message_recipients.message_id";

        List<Message> messages = new ArrayList<>();

        try (Connection connection = getConnection(url, user, password);
             PreparedStatement preparedStatement = connection.prepareStatement(sql);
             ResultSet resultSet = preparedStatement.executeQuery()) {

            Map<Long, Message> messageMap = new HashMap<>();

            while (resultSet.next()) {
                Long messageId = resultSet.getLong("id");
                messageMap.computeIfAbsent(messageId, k -> {
                    return findOne(messageId).get();
                });

            }

            messages.addAll(messageMap.values());

        } catch (SQLException e) {
            e.printStackTrace(); // Handle or log the exception based on your application's needs
        }

        return messages;
    }

    @Override
    public Optional<Message> save(Message entity) {
        String insertMessageSql = "INSERT INTO messages (from_user_id, message_text, date_time) VALUES (?, ?, ?)";
        String insertRecipientSql = "INSERT INTO message_recipients (to_user_id, message_id,  reply_to_message_id) VALUES (?, ?, ?)";

        try (Connection connection = getConnection(url, user, password);
             PreparedStatement insertMessageStatement = connection.prepareStatement(insertMessageSql, Statement.RETURN_GENERATED_KEYS)) {

            // Set parameters for the message
            insertMessageStatement.setLong(1, entity.getFrom().getId());
            insertMessageStatement.setString(2, entity.getMessage());
            insertMessageStatement.setTimestamp(3, Timestamp.valueOf(entity.getDate()));

            // Execute the message insert statement
            int affectedRows = insertMessageStatement.executeUpdate();

            if (affectedRows == 0) {
                return Optional.empty(); // Insert failed
            }

            // Retrieve the generated message ID
            try (ResultSet generatedKeys = insertMessageStatement.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    long messageId = generatedKeys.getLong(1);

                    // Insert recipients if available
                    if (!entity.getTo().isEmpty()) {
                        try (PreparedStatement insertRecipientStatement = connection.prepareStatement(insertRecipientSql)) {
                            for (User toUser : entity.getTo()) {
                                insertRecipientStatement.setLong(1, toUser.getId());
                                insertRecipientStatement.setLong(2, messageId);
                                if (entity.getReplyTo() != null)
                                    insertRecipientStatement.setLong(3, entity.getReplyTo().getId());
                                else insertRecipientStatement.setNull(3, Types.NULL);
                                insertRecipientStatement.addBatch();
                            }
                            insertRecipientStatement.executeBatch();
                        }
                    }

                    // Return the saved message with the generated ID
                    return Optional.of(new Message(messageId, entity.getFrom(), entity.getTo(),
                            entity.getDate(), entity.getMessage(), entity.getReplyTo()));
                }
            }

        } catch (SQLException e) {
            e.printStackTrace(); // Handle or log the exception based on your application's needs
        }

        return Optional.empty();
    }

    @Override
    public Optional<Message> delete(Long longID) {
        try (Connection connection = getConnection(url, user, password);
             PreparedStatement statement = connection.prepareStatement("DELETE FROM messages WHERE ID = ?");) {
            Optional<Message> cv = findOne(longID);
            statement.setLong(1, longID);
            int affectedRows = statement.executeUpdate();
            return affectedRows == 0 ? Optional.empty() : cv;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<Message> update(Message entity) {
        try (Connection connection = getConnection(url, user, password);
             PreparedStatement statement = connection.prepareStatement("UPDATE messages SET from_id = ?, to_id = ?, date = ?, message = ?, WHERE id = ?")) {
            statement.setLong(1, entity.getFrom().getId());
            statement.setLong(2, entity.getTo().get(0).getId());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getDate()));
            statement.setString(4, entity.getMessage());
            // statement.setLong(5,entity.getReplyTo().getId());
            statement.setLong(5, entity.getId());
            int affectedRows = statement.executeUpdate();
            return affectedRows != 0 ? Optional.empty() : Optional.of(entity);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Page<Message> findAll(Pageable pageable, Long user1Id, Long user2Id) {
        try (Connection connection = DriverManager.getConnection(this.url, this.user, this.password);
             PreparedStatement pagePreparedStatement = connection.prepareStatement
                     ("SELECT messages.*, message_recipients.to_user_id " +
                             "FROM messages " +
                             "LEFT JOIN message_recipients ON messages.id = message_recipients.message_id " +
                             "WHERE (messages.from_user_id = ? AND message_recipients.to_user_id = ?) " +
                             "OR (messages.from_user_id = ? AND message_recipients.to_user_id = ?) " +
                             "LIMIT ? OFFSET ?");

             PreparedStatement countPreparedStatement = connection.prepareStatement
                     ("SELECT COUNT(*) AS count " +
                             "FROM messages " +
                             "LEFT JOIN message_recipients ON messages.id = message_recipients.message_id " +
                             "WHERE (messages.from_user_id = ? AND message_recipients.to_user_id = ?) " +
                             "OR (messages.from_user_id = ? AND message_recipients.to_user_id = ?) ");

        ) {
            pagePreparedStatement.setLong(1, user1Id);
            pagePreparedStatement.setLong(2, user2Id);
            pagePreparedStatement.setLong(3, user2Id);
            pagePreparedStatement.setLong(4, user1Id);
            pagePreparedStatement.setInt(5, pageable.getPageSize());
            pagePreparedStatement.setInt(6, pageable.getPageSize() * pageable.getPageNumber());

            countPreparedStatement.setLong(1, user1Id);
            countPreparedStatement.setLong(2, user2Id);
            countPreparedStatement.setLong(3, user2Id);
            countPreparedStatement.setLong(4, user1Id);
            try (ResultSet pageResultSet = pagePreparedStatement.executeQuery();
                 ResultSet countResultSet = countPreparedStatement.executeQuery();) {

                Map<Long, Message> messageMap = new HashMap<>();

                while (pageResultSet.next()) {
                    Long messageId = pageResultSet.getLong("id");
                    messageMap.computeIfAbsent(messageId, k -> {
                        return findOne(messageId).get();
                    });

                }

                List<Message> messageList = new ArrayList<>(messageMap.values());
                int totalCount = 0;
                if (countResultSet.next()) {
                    totalCount = countResultSet.getInt("count");
                }

                return new Page<>(messageList, totalCount);

            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}