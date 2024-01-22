package org.exemplu226.repository;

import org.exemplu226.domain.Nivel;
import org.exemplu226.domain.Participant;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class CoordonatoriRepo implements Repository<Participant> {
    private String url;
    private String usernamee;
    private String passwd;

    public CoordonatoriRepo(String url, String usernamee, String passwd) {
        this.url = url;
        this.usernamee = usernamee;
        this.passwd = passwd;
    }

    @Override
    public List<Participant> getAll() {
        List<Participant> all = new ArrayList<>();
        try (Connection connection = DriverManager.getConnection(url, usernamee, passwd);
             PreparedStatement statement = connection.prepareStatement("SELECT * from participanti");
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String nume = resultSet.getString("nume");
                String prenume = resultSet.getString("prenume");
                String nivel = resultSet.getString("nivel");

                Participant participant = new Participant(id, nume, prenume, Nivel.valueOf(nivel));
                all.add(participant);

            }
            return all;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return all;
    }
}
