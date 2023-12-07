package map.toysocialnetwork;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import map.toysocialnetwork.domain.Message;
import map.toysocialnetwork.domain.validators.FriendshipValidator;
import map.toysocialnetwork.domain.validators.UserValidator;
import map.toysocialnetwork.repository.database.FriendshipDBRepository;
import map.toysocialnetwork.repository.database.MessagesDBRepository;
import map.toysocialnetwork.repository.database.UserDBRepository;
import map.toysocialnetwork.service.SocialNetwork;

import java.io.IOException;
import java.util.Collections;

public class StartApplication extends Application {

    UserDBRepository userDBRepository;
    FriendshipDBRepository friendshipDBRepository;

    MessagesDBRepository messagesDBRepository;
    SocialNetwork socialNetwork;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws IOException {
        userDBRepository = new UserDBRepository(new UserValidator());
        friendshipDBRepository = new FriendshipDBRepository(new FriendshipValidator(userDBRepository));
        messagesDBRepository = new MessagesDBRepository(userDBRepository);


        socialNetwork = new SocialNetwork(userDBRepository, friendshipDBRepository, messagesDBRepository);

        initView(primaryStage);
        primaryStage.setWidth(600);
        primaryStage.setTitle("SocialNetwork");
        primaryStage.show();
    }

    private void initView(Stage primaryStage) throws IOException {

        FXMLLoader fmxlLoader = new FXMLLoader(StartApplication.class.getResource("views/main.fxml"));
        Scene scene = new Scene(fmxlLoader.load());
        primaryStage.setScene(scene);

        Controller controller = fmxlLoader.getController();
        controller.setSocialNetwork(socialNetwork);
        controller.initApp(socialNetwork.getUsers());
    }


}
