package ro.ubb.map.demogui;


import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

import ro.ubb.map.demogui.domain.MessageTask;
import ro.ubb.map.demogui.domain.validators.MessageTaskValidator;
import ro.ubb.map.demogui.repository.InFileMessageTaskRepository;
import ro.ubb.map.demogui.repository.paging.PagingRepository;
import ro.ubb.map.demogui.services.MessageTaskService;


import java.io.IOException;

public class StartApplication extends Application {

    PagingRepository<String, MessageTask> messageTaskRepository;
    MessageTaskService messageTaskService;

    public static void main(String[] args) {
        System.out.println("ok");
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws IOException {
        //System.out.println("ok");
        //String fileN = ApplicationContext.getPROPERTIES().getProperty("data.tasks.messageTask");
        String fileN = "data/messages.txt";
        messageTaskRepository = new InFileMessageTaskRepository
                (fileN, new MessageTaskValidator());
        messageTaskService = new MessageTaskService(messageTaskRepository);
        //messageTaskService.getAll().forEach(System.out::println);

        initView(primaryStage);
        primaryStage.setWidth(800);
        primaryStage.show();
    }

    private void initView(Stage primaryStage) throws IOException {

        FXMLLoader messageLoader = new FXMLLoader();
        messageLoader.setLocation(getClass().getResource("views/messagetask-view.fxml"));
        AnchorPane messageTaskLayout = messageLoader.load();
        primaryStage.setScene(new Scene(messageTaskLayout));

        MessageTaskController messageTaskController = messageLoader.getController();
        messageTaskController.setMessageTaskService(messageTaskService);

    }
}
