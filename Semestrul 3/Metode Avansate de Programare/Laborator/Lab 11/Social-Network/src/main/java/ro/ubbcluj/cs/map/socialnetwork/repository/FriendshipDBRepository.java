package ro.ubbcluj.cs.map.socialnetwork.repository;


import ro.ubbcluj.cs.map.socialnetwork.domain.FriendRequest;
import ro.ubbcluj.cs.map.socialnetwork.domain.Friendship;
import ro.ubbcluj.cs.map.socialnetwork.domain.validators.Validator;

import java.time.LocalDateTime;
import java.util.*;
import java.sql.*;

public class FriendshipDBRepository implements FriendRequestPagingRepository<Long, Friendship> {

    private final String url;
    private final String user;
    private final String password;

    private final Validator<Friendship> validator;


    public FriendshipDBRepository(String url, String user, String password, Validator<Friendship> validator) {
        this.url = url;
        this.user = user;
        this.password = password;
        this.validator = validator;
    }


    @Override
    public Optional<Friendship> findOne(Long longID) {
        try (Connection connection = DriverManager.getConnection(url, user, password);
             PreparedStatement statement = connection.prepareStatement("SELECT * FROM friendships WHERE id=?")) {
            statement.setLong(1, longID);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                Long user1_id = resultSet.getLong("user1_id");
                Long user2_id = resultSet.getLong("user2_id");
                LocalDateTime friends_from = resultSet.getTimestamp("friends_from").toLocalDateTime();
                FriendRequest friend_req_status = FriendRequest.valueOf(resultSet.getString("friend_request_status"));
                Friendship f = new Friendship(user1_id, user2_id, friends_from);
                f.setId(longID);
                return Optional.of(f);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Friendship> findAll() {
        Set<Friendship> friendships = new HashSet<>();

        try (Connection connection = DriverManager.getConnection(url, user, password);
             PreparedStatement statement = connection.prepareStatement("select * from friendships");
             ResultSet resultSet = statement.executeQuery()
        ) {

            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                Long user1_id = resultSet.getLong("user1_id");
                Long user2_id = resultSet.getLong("user2_id");
                LocalDateTime friends_from = resultSet.getTimestamp("friends_from").toLocalDateTime();
                FriendRequest friendship_status = FriendRequest.valueOf(resultSet.getString("friend_request_status"));

                Friendship f = new Friendship(user1_id, user2_id, friends_from, friendship_status);
                f.setId(id);
                friendships.add(f);
            }
            return friendships;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<Friendship> save(Friendship entity) {
        validator.validate(entity);
        try(Connection connection = DriverManager.getConnection(url,user,password);
            PreparedStatement statement  = connection.prepareStatement("INSERT INTO friendships(user1_id,user2_id,friends_from, friend_request_status) VALUES (?,?,?,?)"))
        {
            statement.setLong(1,entity.getUser1Id());
            statement.setLong(2,entity.getUser2Id());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getFriendsFrom()));
            statement.setString(4, entity.getFriendRequestStatus().toString());
            int affectedRows = statement.executeUpdate();
            return affectedRows!=0? Optional.empty():Optional.of(entity);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<Friendship> delete(Long longID) {
        try(Connection connection = DriverManager.getConnection(url,user,password);
            PreparedStatement statement  = connection.prepareStatement("DELETE FROM friendships WHERE ID = ?");)
        {
            Optional<Friendship> cv = findOne(longID);
            statement.setLong(1,longID);
            int affectedRows = statement.executeUpdate();
            return affectedRows==0? Optional.empty():cv;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<Friendship> update(Friendship entity) {
        try(Connection connection = DriverManager.getConnection(url,user,password);
            PreparedStatement statement  = connection.prepareStatement("UPDATE friendships SET user1_id = ?, user2_id = ?, friends_from = ?, friend_request_status = ? WHERE id = ?"))
        {
            statement.setLong(1,entity.getUser1Id());
            statement.setLong(2,entity.getUser2Id());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getFriendsFrom()));
            statement.setString(4, entity.getFriendRequestStatus().toString());
            statement.setLong(5,entity.getId());
            int affectedRows = statement.executeUpdate();
            return affectedRows!=0? Optional.empty():Optional.of(entity);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Page<Friendship> findAll(Pageable pageable) {
        List<Friendship> friendshipList = new ArrayList<>();
        try(Connection connection= DriverManager.getConnection(this.url,this.user,this.password);
            PreparedStatement pagePreparedStatement=connection.prepareStatement("SELECT * FROM friendships WHERE friend_request_status LIKE 'ACCEPTED' " +
                    "LIMIT ? OFFSET ?");

            PreparedStatement countPreparedStatement = connection.prepareStatement
                    ("SELECT COUNT(*) AS count FROM friendships WHERE friend_request_status LIKE 'ACCEPTED' ");

        ) {
            pagePreparedStatement.setInt(1, pageable.getPageSize());
            pagePreparedStatement.setInt(2, pageable.getPageSize() * pageable.getPageNumber());
            try (ResultSet pageResultSet = pagePreparedStatement.executeQuery();
                 ResultSet countResultSet = countPreparedStatement.executeQuery(); ) {
                while (pageResultSet.next()) {
                    Long id = pageResultSet.getLong("id");
                    Long user1_id = pageResultSet.getLong("user1_id");
                    Long user2_id = pageResultSet.getLong("user2_id");
                    LocalDateTime friends_from = pageResultSet.getTimestamp("friends_from").toLocalDateTime();
                    FriendRequest friend_req_status = FriendRequest.valueOf(pageResultSet.getString("friend_request_status"));
                    Friendship friendship = new Friendship(user1_id, user2_id, friends_from, friend_req_status);
                    friendship.setId(id);
                    friendshipList.add(friendship);
                }
                int totalCount = 0;
                if(countResultSet.next()) {
                    totalCount = countResultSet.getInt("count");
                }

                return new Page<>(friendshipList, totalCount);

            }
        }
        catch (SQLException e){
            throw new RuntimeException(e);
        }
    }

    @Override
    public Page<Friendship> findAllFriendRequests(Pageable pageable) {
        List<Friendship> friendshipList = new ArrayList<>();
        try(Connection connection= DriverManager.getConnection(this.url,this.user,this.password);
            PreparedStatement pagePreparedStatement=connection.prepareStatement("SELECT * FROM friendships " +
                    "LIMIT ? OFFSET ?");

            PreparedStatement countPreparedStatement = connection.prepareStatement
                    ("SELECT COUNT(*) AS count FROM friendships");

        ) {
            pagePreparedStatement.setInt(1, pageable.getPageSize());
            pagePreparedStatement.setInt(2, pageable.getPageSize() * pageable.getPageNumber());
            try (ResultSet pageResultSet = pagePreparedStatement.executeQuery();
                 ResultSet countResultSet = countPreparedStatement.executeQuery(); ) {
                while (pageResultSet.next()) {
                    Long id = pageResultSet.getLong("id");
                    Long user1_id = pageResultSet.getLong("user1_id");
                    Long user2_id = pageResultSet.getLong("user2_id");
                    LocalDateTime friends_from = pageResultSet.getTimestamp("friends_from").toLocalDateTime();
                    FriendRequest friend_req_status = FriendRequest.valueOf(pageResultSet.getString("friend_request_status"));
                    Friendship friendship = new Friendship(user1_id, user2_id, friends_from, friend_req_status);
                    friendship.setId(id);
                    friendshipList.add(friendship);
                }
                int totalCount = 0;
                if(countResultSet.next()) {
                    totalCount = countResultSet.getInt("count");
                }

                return new Page<>(friendshipList, totalCount);

            }
        }
        catch (SQLException e){
            throw new RuntimeException(e);
        }
    }

    @Override
    public Page<Friendship> findAllUserFriends(Pageable pageable, Long idU) {
        List<Friendship> friendshipList = new ArrayList<>();
        try(Connection connection= DriverManager.getConnection(this.url,this.user,this.password);
            PreparedStatement pagePreparedStatement=connection.prepareStatement("SELECT * FROM friendships WHERE (friendships.friend_request_status LIKE 'ACCEPTED' AND (friendships.user1_id = ? OR friendships.user2_id = ?)) " +
                    "LIMIT ? OFFSET ?");

            PreparedStatement countPreparedStatement = connection.prepareStatement
                    ("SELECT COUNT(*) AS count FROM friendships");

        ) {
            pagePreparedStatement.setLong(1, idU);
            pagePreparedStatement.setLong(2, idU);
            pagePreparedStatement.setInt(3, pageable.getPageSize());
            pagePreparedStatement.setInt(4, pageable.getPageSize() * pageable.getPageNumber());
            try (ResultSet pageResultSet = pagePreparedStatement.executeQuery();
                 ResultSet countResultSet = countPreparedStatement.executeQuery(); ) {
                while (pageResultSet.next()) {
                    Long id = pageResultSet.getLong("id");
                    Long user1_id = pageResultSet.getLong("user1_id");
                    Long user2_id = pageResultSet.getLong("user2_id");
                    LocalDateTime friends_from = pageResultSet.getTimestamp("friends_from").toLocalDateTime();
                    FriendRequest friend_req_status = FriendRequest.valueOf(pageResultSet.getString("friend_request_status"));
                    Friendship friendship = new Friendship(user1_id, user2_id, friends_from, friend_req_status);
                    friendship.setId(id);
                    friendshipList.add(friendship);
                }
                int totalCount = 0;
                if(countResultSet.next()) {
                    totalCount = countResultSet.getInt("count");
                }

                return new Page<>(friendshipList, totalCount);

            }
        }
        catch (SQLException e){
            throw new RuntimeException(e);
        }
    }

    @Override
    public Page<Friendship> findAllUserFriendRequests(Pageable pageable, Long idU) {
        List<Friendship> friendshipList = new ArrayList<>();
        try(Connection connection= DriverManager.getConnection(this.url,this.user,this.password);
            PreparedStatement pagePreparedStatement=connection.prepareStatement("SELECT * FROM friendships WHERE (friendships.user1_id = ? OR friendships.user2_id = ?) " +
                    "LIMIT ? OFFSET ?");

            PreparedStatement countPreparedStatement = connection.prepareStatement
                    ("SELECT COUNT(*) AS count FROM friendships  WHERE (friendships.user1_id = ? OR friendships.user2_id = ?) ");

        ) {
            pagePreparedStatement.setLong(1, idU);
            pagePreparedStatement.setLong(2, idU);
            pagePreparedStatement.setInt(3, pageable.getPageSize());
            pagePreparedStatement.setInt(4, pageable.getPageSize() * pageable.getPageNumber());

            countPreparedStatement.setLong(1, idU);
            countPreparedStatement.setLong(2, idU);
            try (ResultSet pageResultSet = pagePreparedStatement.executeQuery();
                 ResultSet countResultSet = countPreparedStatement.executeQuery(); ) {
                while (pageResultSet.next()) {
                    Long id = pageResultSet.getLong("id");
                    Long user1_id = pageResultSet.getLong("user1_id");
                    Long user2_id = pageResultSet.getLong("user2_id");
                    LocalDateTime friends_from = pageResultSet.getTimestamp("friends_from").toLocalDateTime();
                    FriendRequest friend_req_status = FriendRequest.valueOf(pageResultSet.getString("friend_request_status"));
                    Friendship friendship = new Friendship(user1_id, user2_id, friends_from, friend_req_status);
                    friendship.setId(id);
                    friendshipList.add(friendship);
                }
                int totalCount = 0;
                if(countResultSet.next()) {
                    totalCount = countResultSet.getInt("count");
                }

                return new Page<>(friendshipList, totalCount);

            }
        }
        catch (SQLException e){
            throw new RuntimeException(e);
        }
    }
}
