package ro.ubbcluj.cs.map.socialnetwork.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import ro.ubbcluj.cs.map.socialnetwork.domain.User;
import ro.ubbcluj.cs.map.socialnetwork.service.Service;

public class LogInController {

    private Service service;

    @FXML
    private Button closeAppBtn;

    @FXML
    private TextField emailTxtField;

    @FXML
    private Hyperlink signUpHLink;

    @FXML
    private Button logInBtn;

    @FXML
    private PasswordField passwordTxtField;

    public void setService(Service service) {
        this.service = service;
    }

    @FXML
    void closeApp(MouseEvent event) {
        System.exit(0);
    }

    @FXML
    void signUpWindow(ActionEvent event)  {
        try {
            FXMLLoader stageLoader = new FXMLLoader();
            stageLoader.setLocation(getClass().getResource("/ro/ubbcluj/cs/map/socialnetwork/signUp.fxml"));

            Stage stage = (Stage)((Node)event.getSource()).getScene().getWindow();

            BorderPane singUpLayout = stageLoader.load();
            Scene scene = new Scene(singUpLayout);
            stage.setScene(scene);

            SignUpController signUpController = stageLoader.getController();
            signUpController.setService(this.service);
            // signUpController.setMessageService(messageService);

            stage.show();

        } catch (Exception e) {
            System.out.println(e.getMessage());;
        }
    }

    @FXML
    void logIn(MouseEvent event) {
        String email = emailTxtField.getText();
        String password = passwordTxtField.getText();

        User u = service.getUserByEmail(email);
        if (u == null) {
            System.out.println("nu exista cont cu acest mail");
            return;
        }

        User user = service.findUser(u.getId().toString());
        if (user.getPassword().equals(password)) {
            try {
                FXMLLoader stageLoader = new FXMLLoader();
                stageLoader.setLocation(getClass().getResource("/ro/ubbcluj/cs/map/socialnetwork/application.fxml"));

                Stage stage = (Stage)((Node)event.getSource()).getScene().getWindow();

                TabPane appLayout = stageLoader.load();
                Scene scene = new Scene(appLayout);
                stage.setScene(scene);

                ApplicationController appController = stageLoader.getController();
                appController.setService(this.service);
                appController.setUserLogged(user);
                appController.initApp();
                stage.show();

            } catch (Exception e) {
                System.out.println(e.getMessage());;
            }
        } else {
            System.out.println("nope");
        }
    }

}
