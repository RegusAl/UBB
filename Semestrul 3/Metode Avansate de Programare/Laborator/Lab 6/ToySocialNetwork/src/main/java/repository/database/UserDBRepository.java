package repository.database;

import domain.User;
import domain.validators.UserValidator;
import domain.validators.Validator;
import repository.Repository;

import java.sql.*;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class UserDBRepository implements Repository<Long, User> {

//    String url;
//    String username;
//    String password;
//
//    public UserDBRepository(String url, String username, String password) {
//        this.url = url;
//        this.username = username;
//        this.password = password;
//    }

    UserValidator userValidator;

    public UserDBRepository(UserValidator userValidator) {
        this.userValidator = userValidator;
    }


    @Override
    public Optional<User> findOne(Long aLong) {
        return Optional.empty();
    }

    @Override
    public Iterable<User> findAll() {
        Set<User> userSet = new HashSet<>();
        try (Connection connection = DriverManager.getConnection("jdbc:postgresql://localhost:5432/socialnetwork", "albert", "admin");
             PreparedStatement statement = connection.prepareStatement("select * from users");
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String nume = resultSet.getString("first_name");
                String prenume = resultSet.getString("last_name");
                User user = new User(nume, prenume);
                user.setId(id);

                userSet.add(user);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return userSet;
    }

    @Override
    public Optional<User> save(User entity) {
        return Optional.empty();
    }

    @Override
    public Optional<User> delete(Long aLong) {
        return Optional.empty();
    }

    @Override
    public Optional<User> update(User entity) {
        return Optional.empty();
    }
}
