package org.comenzirestaurant.repository.db;

import com.example.restaurante.domain.MenuItem;
import com.example.restaurante.domain.Table;
import com.example.restaurante.exceptions.InexistentEntityException;
import com.example.restaurante.repository.Repository;

import java.sql.*;
import java.util.*;

public class MenuItemsDbRepository implements Repository<Integer, MenuItem> {
    private String url;
    private String username;
    private String password;

    public MenuItemsDbRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    private MenuItem getMenuItemFromResultSet(ResultSet resultSet) throws SQLException {
        Integer id = resultSet.getInt("id");
        String category = resultSet.getString("category");
        String item = resultSet.getString("item");
        Float price = resultSet.getFloat("price");
        String currency = resultSet.getString("currency");

        return new MenuItem(id, category, item, price, currency);
    }

    private boolean exists(Integer id) {
        String sql = "SELECT * FROM menu_items WHERE id = ?";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setInt(1, id);
            ResultSet resultSet = statement.executeQuery();

            if(resultSet.next()) {
                return true;
            }
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }

        return false;
    }

    @Override
    public MenuItem find(Integer id) {
        if(username == null) {
            throw new IllegalArgumentException("Id must be not null!");
        }

        String sql = "SELECT * FROM menu_items WHERE id = ?";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setInt(1, id);
            ResultSet resultSet = statement.executeQuery();

            if(!resultSet.next()) {
                throw new InexistentEntityException(id + " does not exist!");
            } else {
                return getMenuItemFromResultSet(resultSet);
            }

        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }

        return null;
    }

    @Override
    public Iterable<MenuItem> getAll() {
        List<MenuItem> menuItems = new ArrayList<>();
        String sql = "SELECT * FROM menu_items";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery()) {

            while(resultSet.next()) {
                MenuItem menuItem = getMenuItemFromResultSet(resultSet);
                menuItems.add(menuItem);
            }
        }catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return menuItems;
    }

    @Override
    public Map<Integer, MenuItem> getMap() {
        Map<Integer, MenuItem> menuItems = new HashMap<>();
        String sql = "SELECT * FROM menu_items";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery()) {

            while(resultSet.next()) {
                MenuItem menuItem = getMenuItemFromResultSet(resultSet);
                menuItems.put(menuItem.getId(), menuItem);
            }
        }catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return menuItems;
    }

    @Override
    public void clear() {
        String sql = "DELETE FROM menu_items";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql);
        ) {
            statement.executeUpdate();
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
    }
}
