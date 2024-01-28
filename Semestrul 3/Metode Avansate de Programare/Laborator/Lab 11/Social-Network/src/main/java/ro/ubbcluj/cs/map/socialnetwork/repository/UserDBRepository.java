package ro.ubbcluj.cs.map.socialnetwork.repository;



import ro.ubbcluj.cs.map.socialnetwork.domain.User;
import ro.ubbcluj.cs.map.socialnetwork.domain.validators.Validator;

import java.sql.*;
import java.util.*;

public class UserDBRepository implements PagingRepository<Long, User> {
    private final String url;
    private final String user;
    private final String password;

    private final Validator<User> validator;

    public UserDBRepository(String url, String user, String password, Validator<User> validator) {
        this.url = url;
        this.user = user;
        this.password = password;
        this.validator = validator;
    }


    @Override
    public Optional<User> findOne(Long longID) {
        try (Connection connection = DriverManager.getConnection(url, user, password);
             PreparedStatement statement = connection.prepareStatement("SELECT * FROM users " +
                     "LEFT JOIN passwords ON passwords.id = users.id " +
                     "WHERE users.id=? ");) {
            statement.setLong(1, longID);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");
                String email = resultSet.getString("email");
                String password = resultSet.getString("password");
                User u = new User(firstName, lastName, email);
                u.setId(longID);
                u.setPassword(password);
                u.setPassword(u.decryptPassword(1));
                return Optional.of(u);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }

    @Override
    public Iterable<User> findAll() {
        Set<User> users = new HashSet<>();

        try (Connection connection = DriverManager.getConnection(url, user, password);
             PreparedStatement statement = connection.prepareStatement("select * from users");
             ResultSet resultSet = statement.executeQuery()
        ) {

            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");
                String email = resultSet.getString("email");
                User user = new User(firstName, lastName, email);
                user.setId(id);
                users.add(user);
            }
            return users;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<User> save(User entity) {
        validator.validate(entity);
        try(Connection connection = DriverManager.getConnection(url,user,password);
            PreparedStatement statement  = connection.prepareStatement("INSERT INTO users(first_name,last_name,email) VALUES (?,?,?)", Statement.RETURN_GENERATED_KEYS);
            PreparedStatement passwordStatement = connection.prepareStatement("INSERT INTO passwords(id, password) VALUES (?, ?)"))
        {
            statement.setString(1,entity.getFirstName());
            statement.setString(2,entity.getLastName());
            statement.setString(3,entity.getEmail());
            int affectedRows = statement.executeUpdate();

            try (ResultSet generatedKeys = statement.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    long generatedId = generatedKeys.getLong(1);
                    passwordStatement.setLong(1, generatedId);
                    passwordStatement.setString(2, entity.encryptPassword(1));

                    passwordStatement.executeUpdate();
                } else {
                    System.out.println("No ID obtained.");
                }
            }

            return affectedRows!=0? Optional.empty():Optional.of(entity);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<User> delete(Long longID) {
        try(Connection connection = DriverManager.getConnection(url,user,password);
            PreparedStatement statement  = connection.prepareStatement("DELETE FROM users WHERE ID = ?");)
        {
            Optional<User> cv = findOne(longID);
            statement.setLong(1,longID);
            int affectedRows = statement.executeUpdate();
            return affectedRows==0? Optional.empty():cv;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<User> update(User entity) {
        validator.validate(entity);
        try(Connection connection = DriverManager.getConnection(url,user,password);
            PreparedStatement statement  = connection.prepareStatement("UPDATE users SET first_name = ?, last_name = ?, email = ? WHERE id = ?");)
        {
            statement.setString(1,entity.getFirstName());
            statement.setString(2,entity.getLastName());
            statement.setString(3,entity.getEmail());
            statement.setLong(4,entity.getId());
            int affectedRows = statement.executeUpdate();
            return affectedRows!=0? Optional.empty():Optional.of(entity);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Page<User> findAll(Pageable pageable) {
        List<User> userList = new ArrayList<>();
        try(Connection connection= DriverManager.getConnection(this.url,this.user,this.password);
            PreparedStatement pagePreparedStatement=connection.prepareStatement("SELECT * FROM users " +
                    "LIMIT ? OFFSET ?");

            PreparedStatement countPreparedStatement = connection.prepareStatement
                    ("SELECT COUNT(*) AS count FROM users ");

        ) {
            pagePreparedStatement.setInt(1, pageable.getPageSize());
            pagePreparedStatement.setInt(2, pageable.getPageSize() * pageable.getPageNumber());
            try (ResultSet pageResultSet = pagePreparedStatement.executeQuery();
                 ResultSet countResultSet = countPreparedStatement.executeQuery(); ) {
                while (pageResultSet.next()) {
                    Long id = pageResultSet.getLong("id");
                    String firstName = pageResultSet.getString("first_name");
                    String lastName = pageResultSet.getString("last_name");
                    String email = pageResultSet.getString("email");
                    User user = new User(firstName, lastName, email);
                    user.setId(id);
                    userList.add(user);
                }
                int totalCount = 0;
                if(countResultSet.next()) {
                    totalCount = countResultSet.getInt("count");
                }

                return new Page<>(userList, totalCount);

            }
        }
        catch (SQLException e){
            throw new RuntimeException(e);
        }
    }
}
