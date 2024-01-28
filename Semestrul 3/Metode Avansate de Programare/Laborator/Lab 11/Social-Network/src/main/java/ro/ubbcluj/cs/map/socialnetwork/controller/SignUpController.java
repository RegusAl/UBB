package ro.ubbcluj.cs.map.socialnetwork.controller;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import ro.ubbcluj.cs.map.socialnetwork.domain.User;
import ro.ubbcluj.cs.map.socialnetwork.service.Service;

public class SignUpController {

    private Service service;
    @FXML
    private PasswordField checkPasswordTxtField;

    @FXML
    private TextField emailTxtField;

    @FXML
    private TextField firstNameTxtField;

    @FXML
    private TextField lastNameTxtField;

    @FXML
    private PasswordField passwordTxtField;

    @FXML
    private Button signUpBtn;

    public void setService(Service service) {
        this.service = service;
    }

    @FXML
    void signUp(MouseEvent event) {
        String firstName = firstNameTxtField.getText();
        String lastName = lastNameTxtField.getText();
        String email = emailTxtField.getText();
        String password = passwordTxtField.getText();
        service.addUser(firstName, lastName, email, password);
        try {
            FXMLLoader stageLoader = new FXMLLoader();
            stageLoader.setLocation(getClass().getResource("/ro/ubbcluj/cs/map/socialnetwork/application.fxml"));

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();

            TabPane appLayout = stageLoader.load();
            Scene scene = new Scene(appLayout);
            stage.setScene(scene);

            ApplicationController appController = stageLoader.getController();
            appController.setService(this.service);
            appController.setUserLogged(service.getUserByEmail(email));

            stage.show();

        } catch (Exception e) {
            System.out.println(e.getMessage());
            ;
        }
    }

    public void logInWindow(MouseEvent event) {
        try {
            FXMLLoader stageLoader = new FXMLLoader();
            stageLoader.setLocation(getClass().getResource("/ro/ubbcluj/cs/map/socialnetwork/logIn.fxml"));
            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();

            BorderPane singUpLayout = stageLoader.load();
            Scene scene = new Scene(singUpLayout);
            stage.setScene(scene);

            SignUpController signUpController = stageLoader.getController();
            signUpController.setService(this.service);

            stage.show();

        } catch (Exception e) {
            System.out.println(e.getMessage());
            ;
        }
    }
}
