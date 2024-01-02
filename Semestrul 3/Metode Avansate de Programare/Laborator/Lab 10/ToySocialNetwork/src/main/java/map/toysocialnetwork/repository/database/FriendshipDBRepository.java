package map.toysocialnetwork.repository.database;


import map.toysocialnetwork.domain.Friendship;
import map.toysocialnetwork.domain.validators.FriendshipValidator;
import map.toysocialnetwork.enums.FriendshipRequest;
import map.toysocialnetwork.repository.Repository;

import java.sql.*;
import java.time.LocalDateTime;
import java.time.ZoneOffset;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Optional;

public class FriendshipDBRepository implements Repository<Long, Friendship> {

    FriendshipValidator friendshipValidator;

    public FriendshipDBRepository(FriendshipValidator friendshipValidator) {
        this.friendshipValidator = friendshipValidator;
    }

    @Override
    public Optional<Friendship> findOne(Long aLong) {
        String query = "SELECT * FROM friendships WHERE \"id\" = ?";
        Friendship friendship = null;
        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement(query);) {

            statement.setLong(1, aLong);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                Long idFriend1 = resultSet.getLong("idfriend1");
                Long idFriend2 = resultSet.getLong("idfriend2");
                Timestamp date = resultSet.getTimestamp("friendsfrom");
                LocalDateTime friendsFrom = new Timestamp(date.getTime()).toLocalDateTime();
                FriendshipRequest friendshipRequest = FriendshipRequest.valueOf(resultSet.getString("friend_request_status"));
                friendship = new Friendship(idFriend1, idFriend2, friendsFrom, friendshipRequest);
                friendship.setId(aLong);
                return Optional.of(friendship);
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Friendship> findAll() {
        Map<Long, Friendship> friendships = new HashMap<>();
        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement("SELECT * FROM friendships");
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                Long idFriend1 = resultSet.getLong("idfriend1");
                Long idFriend2 = resultSet.getLong("idfriend2");
                Timestamp date = resultSet.getTimestamp("friendsfrom");
                LocalDateTime friendsFrom = LocalDateTime.ofInstant(date.toInstant(), ZoneOffset.ofHours(0));
                FriendshipRequest friendshipRequest = FriendshipRequest.valueOf(resultSet.getString("friend_request_status"));
                Friendship friendship = new Friendship(idFriend1, idFriend2, friendsFrom, friendshipRequest);
                friendship.setId(id);
                friendships.put(friendship.getId(), friendship);
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return friendships.values();
    }

    @Override
    public Optional<Friendship> save(Friendship entity) {
        if (entity == null) {
            throw new IllegalArgumentException("Friendship can't be null!");
        }
        String query = "INSERT INTO friendships(\"id\", \"idfriend1\", \"idfriend2\", \"friendsfrom\", \"friend_request_status\") VALUES (?,?,?,?,?)";

        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement(query);) {
            statement.setLong(1, entity.getId());
            statement.setLong(2, entity.getIdUser1());
            statement.setLong(3, entity.getIdUser2());
            statement.setTimestamp(4, Timestamp.valueOf(entity.getDate()));
            statement.setString(5, entity.getFriendshipRequestStatus().toString());
            statement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return Optional.of(entity);
    }

    @Override
    public Optional<Friendship> delete(Long aLong) {
        String query = "DELETE FROM friendships WHERE \"id\" = ?";

        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement(query);) {
            statement.setLong(1, aLong);
            statement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }

    @Override
    public Optional<Friendship> update(Friendship entity) {
        String query = "UPDATE friendships SET idfriend1 = ?, idfriend2 = ?, friendsfrom = ?, friend_request_status = ? WHERE id = ?";
        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement(query);) {
            statement.setLong(1, entity.getIdUser1());
            statement.setLong(2, entity.getIdUser2());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getDate()));
            statement.setString(4, entity.getFriendshipRequestStatus().toString());
            statement.setLong(5, entity.getId());
            int affectedRows = statement.executeUpdate();
            return Optional.of(entity);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
