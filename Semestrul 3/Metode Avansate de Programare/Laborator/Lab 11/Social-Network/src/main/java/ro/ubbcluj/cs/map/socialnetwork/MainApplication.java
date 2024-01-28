package ro.ubbcluj.cs.map.socialnetwork;


import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import ro.ubbcluj.cs.map.socialnetwork.controller.LogInController;
import ro.ubbcluj.cs.map.socialnetwork.domain.Friendship;
import ro.ubbcluj.cs.map.socialnetwork.domain.Message;
import ro.ubbcluj.cs.map.socialnetwork.domain.User;
import ro.ubbcluj.cs.map.socialnetwork.domain.validators.FriendshipValidator;
import ro.ubbcluj.cs.map.socialnetwork.domain.validators.UserValidator;
import ro.ubbcluj.cs.map.socialnetwork.repository.*;
import ro.ubbcluj.cs.map.socialnetwork.service.Service;

import java.io.IOException;

public class MainApplication extends Application {

    private static String url;
    private static String username;
    private static String password;
    private Service service;

    public Service getService() {
        return service;
    }

    public void setService(Service service) {
        this.service = service;
    }

    public static void main(String[] args) {

        url = "jdbc:postgresql://localhost:5432/sn";
        username = "albert";
        password = "admin";

        launch();
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        PagingRepository<Long, User> userRepo = new UserDBRepository(url, username, password, new UserValidator());
        FriendRequestPagingRepository<Long, Friendship> friendshipRepo = new FriendshipDBRepository(url, username, password, new FriendshipValidator());
        MessagePagingRepository<Long, Message> messageRepo = new MessageDBRepository(url, username, password, userRepo);
        service = new Service(userRepo, friendshipRepo, messageRepo);

        initView(primaryStage);
        primaryStage.show();

    }

    private void initView(Stage primaryStage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("logIn.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        primaryStage.setTitle("Social Network");
        primaryStage.setScene(scene);

//        Controller appController = fxmlLoader.getController();
//        appController.setService(this.service);
//        appController.initApp();
        LogInController logInController = fxmlLoader.getController();
        logInController.setService(this.service);
    }
}