package map.toysocialnetwork;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import map.toysocialnetwork.domain.Friendship;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.domain.validators.UserValidator;
import map.toysocialnetwork.domain.validators.ValidationException;
import map.toysocialnetwork.service.SocialNetwork;

import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

import static map.toysocialnetwork.controller.MessageUser.showErrorMessage;

public class UsersController implements Initializable {


    SocialNetwork socialNetwork;

    UserValidator userValidator;
    ObservableList<User> userObs = FXCollections.observableArrayList();
    ObservableList<Friendship> friendshipModel = FXCollections.observableArrayList();

    // User Window

    @FXML
    private ListView<User> listUsers;

    @FXML
    public TextField textFieldId;

    @FXML
    public TextField textFieldFirstName;

    @FXML
    public TextField textFieldLastName;

    // Friendship Window

    @FXML
    private ListView<Friendship> listFriendships;


    public void setSocialNetwork(SocialNetwork sn) {
        socialNetwork = sn;
    }


    @Override
    public void initialize(URL location, ResourceBundle resources) {
        listUsers.setItems(userObs);
        listFriendships.setItems(friendshipModel);
    }

    public void initApp(Iterable<User> users) {
        listUsers.getItems().clear();
        listFriendships.getItems().clear();
        for (User user : users) {
            userObs.add(user);
        }

        for (Friendship friendship: socialNetwork.getFriendships()) {
            friendshipModel.add(friendship);
        }

    }

    public void addUser(javafx.scene.input.MouseEvent mouseEvent) {
        String id = textFieldId.getText();
        String firstName = textFieldFirstName.getText();
        String lastName = textFieldLastName.getText();
        Long idUser = 0L;

        try {
            idUser = Long.parseLong(id);
            User user = new User(idUser, firstName, lastName);
            socialNetwork.addUser(user);
        } catch (ValidationException ve) {
            showErrorMessage(null, "no");
        } catch (Exception e) {
            System.out.println("id is not number");
            showErrorMessage(null, "User can't be added!");
            textFieldId.clear();
            textFieldFirstName.clear();
            textFieldLastName.clear();
        }

        textFieldId.clear();
        textFieldFirstName.clear();
        textFieldLastName.clear();

        initApp(socialNetwork.getUsers());
    }

    public void deleteUser(MouseEvent mouseEvent) {
        if(listUsers.getSelectionModel().getSelectedItems() != null) {
            User user = listUsers.getSelectionModel().getSelectedItem();
            socialNetwork.removeUser(user.getId());
            initApp(socialNetwork.getUsers());
        }
    }

    public void updateUser(MouseEvent mouseEvent) {
        String id = textFieldId.getText();
        String firstName = textFieldFirstName.getText();
        String lastName = textFieldLastName.getText();
        Long idUser = 0L;
        Long idToUpdate = 0L;

        if(listUsers.getSelectionModel().getSelectedItems() != null) {
            User user = listUsers.getSelectionModel().getSelectedItem();
            idToUpdate = user.getId();
        }

        try {
            idUser = Long.parseLong(id);
            User user = new User(idUser, firstName, lastName);
            socialNetwork.addUser(user);
            socialNetwork.removeUser(idToUpdate);
        } catch (ValidationException ve) {
            showErrorMessage(null, "no");
        } catch (Exception e) {
            System.out.println("id is not number");
            showErrorMessage(null, "User can't be updated!");
            textFieldId.clear();
            textFieldFirstName.clear();
            textFieldLastName.clear();
        }

        textFieldId.clear();
        textFieldFirstName.clear();
        textFieldLastName.clear();

        initApp(socialNetwork.getUsers());
    }

    public void deleteFriendship(MouseEvent mouseEvent) {
        if(listFriendships.getSelectionModel().getSelectedItems() != null) {
            Friendship friendship = listFriendships.getSelectionModel().getSelectedItem();
            socialNetwork.removeFriendship(friendship.getIdUser1(), friendship.getIdUser2());
            initApp(socialNetwork.getUsers());
        }
    }
}
