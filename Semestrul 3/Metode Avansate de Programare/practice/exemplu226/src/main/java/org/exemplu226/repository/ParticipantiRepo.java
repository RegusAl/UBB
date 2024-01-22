package org.exemplu226.repository;

import com.example.rezerva.domain.Table;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class TableRepo implements Repository<Table>{
    private String url;
    private String usernamee;
    private String passwd;

    public TableRepo(String url, String usernamee, String passwd) {
        this.url = url;
        this.usernamee = usernamee;
        this.passwd = passwd;
    }

    @Override
    public List<Table> getAll() {
        List<Table> all = new ArrayList<>();
        try (Connection connection = DriverManager.getConnection(url, usernamee, passwd);
             PreparedStatement statement = connection.prepareStatement("SELECT * from tableee");
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Integer id = resultSet.getInt("id");

                Table table=new Table(id);
                all.add(table);
            }
            return all;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return all;
    }
}
