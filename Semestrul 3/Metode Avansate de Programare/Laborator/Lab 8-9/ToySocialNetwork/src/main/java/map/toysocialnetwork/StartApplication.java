package map.toysocialnetwork;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import map.toysocialnetwork.domain.Entity;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.domain.validators.FriendshipValidator;
import map.toysocialnetwork.domain.validators.UserValidator;
import map.toysocialnetwork.repository.database.FriendshipDBRepository;
import map.toysocialnetwork.repository.database.UserDBRepository;
import map.toysocialnetwork.service.SocialNetwork;

import java.io.IOException;

public class StartApplication extends Application {

    UserDBRepository userDBRepository;
    FriendshipDBRepository friendshipDBRepository;
    SocialNetwork socialNetwork;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws IOException {
        userDBRepository = new UserDBRepository(new UserValidator());
        friendshipDBRepository = new FriendshipDBRepository(new FriendshipValidator(userDBRepository));
        socialNetwork = new SocialNetwork(userDBRepository, friendshipDBRepository);
        initView(primaryStage);
        primaryStage.setWidth(600);
        primaryStage.setTitle("SocialNetwork");
        primaryStage.show();
    }

    private void initView(Stage primaryStage) throws IOException {

        FXMLLoader fmxlLoader = new FXMLLoader(StartApplication.class.getResource("views/main.fxml"));
        Scene scene = new Scene(fmxlLoader.load());
        primaryStage.setScene(scene);

        UsersController usersController = fmxlLoader.getController();
        usersController.setSocialNetwork(socialNetwork);
        usersController.initApp(socialNetwork.getUsers());
    }


}
