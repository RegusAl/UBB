package org.comenzirestaurant.repository.db;

import com.example.restaurante.domain.*;
import com.example.restaurante.exceptions.ExistentEntityException;
import com.example.restaurante.exceptions.InexistentEntityException;
import com.example.restaurante.repository.Repository;
import com.example.restaurante.utils.observer.ConcreteObservable;
import com.example.restaurante.utils.utils.OrderEvent;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.*;
import java.util.concurrent.atomic.AtomicReference;

import static com.example.restaurante.utils.utils.ChangeEventType.ADD;
import static com.example.restaurante.utils.utils.ChangeEventType.UPDATE;

public class OrdersDbRepository extends ConcreteObservable<OrderEvent> implements Repository<Integer, Order> {

    private String url;
    private String username;
    private String password;

    public OrdersDbRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    private Order getOrderFromResultSet(ResultSet resultSet) throws SQLException {
        Integer order_id = 0, table_id = 0;
        LocalDateTime order_date = LocalDateTime.now();
        List<OrderItem> orderItems = new ArrayList<>();
        OrderStatus orderStatus = OrderStatus.PLACED;

        do {
            order_id = resultSet.getInt("order_id");
            table_id = resultSet.getInt("table_id");
            order_date = resultSet.getTimestamp("order_date").toLocalDateTime();
            orderStatus = OrderStatus.valueOf(resultSet.getString("status"));
            Integer item_id = resultSet.getInt("item_id");
            String item_category = resultSet.getString("item_category");
            String item_item = resultSet.getString("item_item");
            Float item_price = resultSet.getFloat("item_price");
            String item_currency = resultSet.getString("item_currency");
            Integer item_quantity = resultSet.getInt("item_quantity");

            orderItems.add(new OrderItem(new MenuItem(item_id, item_category, item_item, item_price, item_currency), item_quantity));
        } while(resultSet.next());

        return new Order(order_id, new Table(table_id), order_date, orderItems, orderStatus);
    }

    private boolean exists(Integer id) {
        String sql = "SELECT * FROM orders WHERE id = ?";

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
    public Order find(Integer id) {
        if(id == null) {
            throw new IllegalArgumentException("Id must be not null!");
        }

        String sql = "SELECT o.id as order_id, o.status as status, o.table_id AS table_id, o.date AS order_date, mi.id as item_id, mi.category as item_category, mi.item as item_item, mi.price as item_price, mi.currency as item_currency, oi.quantity as item_quantity FROM orders o INNER JOIN order_items oi ON oi.order_id = o.id INNER JOIN menu_items mi ON mi.id = oi.item_id WHERE o.id = ?";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql)) {

            statement.setInt(1, id);
            ResultSet resultSet = statement.executeQuery();

            if(!resultSet.next()) {
                throw new InexistentEntityException(id + " does not exist!");
            } else {
                return getOrderFromResultSet(resultSet);
            }

        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }

        return null;
    }

    public void add(Order order) {
        AtomicReference<String> sql = new AtomicReference<>("INSERT INTO orders(table_id, date, status) VALUES(?, ?, ?)");

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql.get())){
            statement.setInt(1, order.getTable().getId());
            statement.setTimestamp(2, Timestamp.valueOf(order.getDate()));
            statement.setString(3, order.getOrderStatus().toString());

            statement.executeUpdate();
        }catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }

        Integer orderId = 0;

        sql.set("SELECT id FROM orders WHERE table_id = ? AND date = ? AND status = ?");

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql.get())) {

            statement.setInt(1, order.getTable().getId());
            statement.setTimestamp(2, Timestamp.valueOf(order.getDate()));
            statement.setString(3, order.getOrderStatus().toString());
            ResultSet resultSet = statement.executeQuery();

            if(resultSet.next()) {
                orderId = resultSet.getInt("id");
            }
        }catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }

        Integer finalOrderId = orderId;
        order.getOrderItems().forEach(orderItem -> {
            sql.set("INSERT INTO order_items(order_id, item_id, quantity) VALUES(?, ?, ?)");
            try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
                PreparedStatement statement = connection.prepareStatement(sql.get())){
                statement.setInt(1, finalOrderId);
                statement.setInt(2, orderItem.getMenuItem().getId());
                statement.setInt(3, orderItem.getQuantity());

                statement.executeUpdate();
            }catch (SQLException sqlException) {
                sqlException.printStackTrace();
            }
        });

        this.notifyObservers(new OrderEvent(ADD, this.find(orderId)));
    }

    public void update(Order order) {
        if(!exists(order.getId())) {
            throw new InexistentEntityException("Inexistent order");
        }

        String sql = "UPDATE orders SET status = ? WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql)){

            statement.setString(1, order.getOrderStatus().toString());
            statement.setInt(2, order.getId());

            statement.executeUpdate();
        }catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }

        this.notifyObservers(new OrderEvent(UPDATE, this.find(order.getId())));
    }

    @Override
    public Iterable<Order> getAll() {
        List<Order> orders = new ArrayList<>();
        String sql = "SELECT id FROM orders ORDER BY date";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery()) {

            while(resultSet.next()) {
                Integer order_id = resultSet.getInt("id");
                Order order = find(order_id);
                orders.add(order);
            }
        }catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return orders;
    }

    @Override
    public Map<Integer, Order> getMap() {
        Map<Integer, Order> orders = new HashMap<>();
        String sql = "SELECT id FROM orders ORDER BY date";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery()) {

            while(resultSet.next()) {
                Integer order_id = resultSet.getInt("id");
                Order order = find(order_id);
                orders.put(order.getId(), order);
            }
        }catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return orders;
    }

    @Override
    public void clear() {
        String sql = "DELETE FROM orders";

        try(Connection connection = DriverManager.getConnection(this.url, this.username, this.password);
            PreparedStatement statement = connection.prepareStatement(sql);
        ) {
            statement.executeUpdate();
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
    }
}
