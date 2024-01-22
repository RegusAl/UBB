package org.exemplu226.repository;

import org.exemplu226.domain.Coordonator;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class DrumetiiRepo implements Repository<Coordonator> {
    private String url;
    private String usernamee;
    private String passwd;

    public DrumetiiRepo(String url, String usernamee, String passwd) {
        this.url = url;
        this.usernamee = usernamee;
        this.passwd = passwd;
    }

    @Override
    public List<Coordonator> getAll() {
        List<Coordonator> all = new ArrayList<>();
        try (Connection connection = DriverManager.getConnection(url, usernamee, passwd);
             PreparedStatement statement = connection.prepareStatement("SELECT * from coordonatori");
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String nume = resultSet.getString("nume");
                String prenume = resultSet.getString("prenume");

                Coordonator coordonator = new Coordonator(id, nume, prenume);
                all.add(coordonator);

            }
            return all;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return all;
    }
}
