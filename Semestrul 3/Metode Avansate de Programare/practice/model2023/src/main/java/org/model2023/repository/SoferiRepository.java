package org.model2023.repository;

import org.model2023.domain.Persoana;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class SoferiRepository implements Repository<Long, Persoana>{
    protected String url;

    protected String username;
    protected String password;

    public SoferiRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    @Override
    public Persoana findOne(Long aLong) {
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("select * from persoane where id = ?");)
        {
            statement.setLong(1, aLong);
            ResultSet resultSet=statement.executeQuery();
            if(resultSet.next()) {
                String nume = resultSet.getString("nume");
                String utilizator = resultSet.getString("utilizator");
                Persoana persoana = new Persoana(utilizator, nume);
                persoana.setId(aLong);
                return persoana;
            }
            return null;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Persoana findByUsername(String utilizator) {
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("select * from persoane where utilzator = ?");)
        {
            statement.setString(1, utilizator);
            ResultSet resultSet=statement.executeQuery();
            if(resultSet.next()) {
                Long id = resultSet.getLong("id");
                String nume = resultSet.getString("nume");
                Persoana persoana = new Persoana(utilizator, nume);
                persoana.setId(id);
                return persoana;
            }
            return null;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public List<Persoana> findAll() {
        List<Persoana> persoane=new ArrayList<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("select * from persoane");)
        {
            ResultSet resultSet=statement.executeQuery();
            while(resultSet.next())
            {
                Long id=resultSet.getLong("id");
                String utilizator=resultSet.getString("utilizator");
                String nume=resultSet.getString("nume");
                Persoana persoana=new Persoana(utilizator,nume);
                persoana.setId(id);
                persoane.add(persoana);
            }
            return persoane;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void save(Persoana elem) {

    }
}
