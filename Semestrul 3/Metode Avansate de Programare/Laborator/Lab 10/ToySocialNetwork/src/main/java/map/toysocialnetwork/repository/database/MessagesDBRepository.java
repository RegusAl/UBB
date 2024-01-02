package map.toysocialnetwork.repository.database;

import map.toysocialnetwork.domain.Message;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.repository.Repository;

import java.lang.reflect.Type;
import java.sql.*;
import java.time.LocalDateTime;
import java.util.*;

public class MessagesDBRepository implements Repository<Long, Message> {

    private Repository<Long, User> userRepository;

    public MessagesDBRepository(Repository<Long, User> userRepository) {
        this.userRepository = userRepository;
    }

    public Optional<Message> findOneNoReply(Long aLong) {
        String query = "SELECT * FROM messages WHERE id = ?";
        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement(query);
        ) {
            statement.setLong(1, aLong);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                Long from_id = resultSet.getLong("from_id");
                Long to_id = resultSet.getLong("to_id");
                String message = resultSet.getString("message");
                LocalDateTime date = resultSet.getTimestamp("date").toLocalDateTime();
                Message msg = new Message(userRepository.findOne(from_id).get(), Collections.singletonList(userRepository.findOne(to_id).get()), message, date);
                msg.setId(aLong);
                return Optional.of(msg);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }

    @Override
    public Optional<Message> findOne(Long aLong) {

        Message msg;
        if (findOneNoReply(aLong).isPresent()) {
            msg = findOneNoReply(aLong).get();
        } else return Optional.empty();

        String query = "SELECT * FROM messages WHERE id = ?";
        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement(query);
        ) {
            statement.setLong(1, aLong);
            ResultSet resultSet = statement.executeQuery();
            Long reply_id = resultSet.getLong("result_id");
            if (!resultSet.next()) {
                Message replyMessage;
                if (findOneNoReply(reply_id).isPresent()) {
                    replyMessage = findOneNoReply(reply_id).get();
                } else return Optional.empty();

                msg.setReply(replyMessage);
                return Optional.of(msg);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }


    @Override
    public Iterable<Message> findAll() {
        List<Message> messages = new ArrayList<>();
        String query = "SELECT * FROM messages";
        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement(query);
        ) {
            ResultSet resultSet = statement.executeQuery();

            while(resultSet.next()) {
                Long id = resultSet.getLong("id");
                Long from_id = resultSet.getLong("from_id");
                Long to_id = resultSet.getLong("to_id");
                LocalDateTime date = resultSet.getTimestamp("date").toLocalDateTime();
                String message = resultSet.getString("message");
                Long reply_id = resultSet.getLong("reply_id");
                User from = userRepository.findOne(from_id).get();
                List<User> to = Collections.singletonList(userRepository.findOne(to_id).get());
                Message msg = new Message(from, to, message, date);
                msg.setId(id);
                messages.add(msg);
            }

        } catch(SQLException e) {
            throw new RuntimeException(e);
        }
        return messages;
    }

    @Override
    public Optional<Message> save(Message entity) {

        String query = "INSERT INTO messages(from_id, to_id, date, message, reply_id) VALUES (?,?,?,?,?)";

        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
            PreparedStatement statement = connection.prepareStatement(query);) {
            statement.setLong(1, entity.getFrom().getId());
            statement.setLong(2, entity.getTo().get(0).getId());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getData()));
            statement.setString(4, entity.getMessage());
            if(entity.getReply() == null) {
                statement.setNull(5, Types.NULL);
            } else statement.setLong(5, entity.getReply().getId());
            statement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return Optional.of(entity);
    }

    @Override
    public Optional<Message> delete(Long aLong) {
        String query = "DELETE FROM messages WHERE id = ?";

        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
            PreparedStatement statement = connection.prepareStatement(query);
        ) {
            statement.setLong(1, aLong);
            statement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }

    @Override
    public Optional<Message> update(Message entity) {
        String query = "UPDATE messages SET from_id = ?, to_id = ?, date = ?, message = ?, reply_id = ? WHERE id = ?";
        try(Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
            PreparedStatement statement = connection.prepareStatement(query);
        ) {
            statement.setLong(1, entity.getFrom().getId());
            statement.setLong(2, entity.getTo().get(0).getId());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getData()));
            statement.setString(4, entity.getMessage());
            statement.setLong(5, entity.getReply().getId());
            statement.setLong(6, entity.getId());
            statement.executeUpdate();
            return Optional.of(entity);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
