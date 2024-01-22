package org.examen.repository;

import com.example.model.domain.Persoana;
import com.example.model.domain.Sofer;
import com.example.model.repository.Repository;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class PersoanaRepository implements Repository<Long, Persoana> {
    protected String url;
    protected String username;
    protected String password;


    public PersoanaRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }


    @Override
    public Persoana findOne(Long id) {
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("select * from persoane where id=?");)
        {
            statement.setLong(1,id);
            ResultSet resultSet=statement.executeQuery();
            if(resultSet.next())
            {
                String utilizator=resultSet.getString("utilizator");
                String nume=resultSet.getString("nume");
                Persoana persoana=new Persoana(utilizator,nume);
                persoana.setId(id);
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
            PreparedStatement statement = connection.prepareStatement("select * from persoane where utilizator=?");)
        {
            statement.setString(1,utilizator);
            ResultSet resultSet=statement.executeQuery();
            if(resultSet.next())
            {
                Long id=resultSet.getLong("id");
                String nume=resultSet.getString("nume");
                Persoana persoana=new Persoana(utilizator,nume);
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
