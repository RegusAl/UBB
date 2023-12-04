package map.toysocialnetwork;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import map.toysocialnetwork.controller.MessageUser;
import map.toysocialnetwork.domain.Friendship;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.domain.validators.UserValidator;
import map.toysocialnetwork.domain.validators.ValidationException;
import map.toysocialnetwork.enums.FriendshipRequest;
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

    ObservableList<Friendship> friendshipsRequestsModel = FXCollections.observableArrayList();

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

    // Friendships Requests Window

    @FXML
    private ListView<Friendship> listFriendshipsRequests;

    @FXML
    private TextField idFirstUser;

    @FXML
    private TextField idSecondUser;


    public void setSocialNetwork(SocialNetwork sn) {
        socialNetwork = sn;
    }


    @Override
    public void initialize(URL location, ResourceBundle resources) {
        listUsers.setItems(userObs);
        listFriendships.setItems(friendshipModel);
        listFriendshipsRequests.setItems(friendshipsRequestsModel);
    }

    public void initApp(Iterable<User> users) {
        listUsers.getItems().clear();
        listFriendships.getItems().clear();
        listFriendshipsRequests.getItems().clear();
        for (User user : users) {
            userObs.add(user);
        }

        for (Friendship friendship : socialNetwork.getFriendships()) {
            if (friendship.getFriendshipRequestStatus() == FriendshipRequest.APPROVED)
                friendshipModel.add(friendship);
            System.out.println(friendship.getFriendshipRequestStatus());
            friendshipsRequestsModel.add(friendship);
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
        if (listUsers.getSelectionModel().getSelectedItems() != null) {
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

        if (listUsers.getSelectionModel().getSelectedItems() != null) {
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
        if (listFriendships.getSelectionModel().getSelectedItems() != null) {
            Friendship friendship = listFriendships.getSelectionModel().getSelectedItem();
            socialNetwork.removeFriendship(friendship.getIdUser1(), friendship.getIdUser2());
            initApp(socialNetwork.getUsers());
        }
    }

    public void sendFriendRequest(MouseEvent mouseEvent) {
        String id1 = idFirstUser.getText();
        String id2 = idSecondUser.getText();
        Long id_1 = 0L, id_2 = 0L;
        try {
            id_1 = Long.parseLong(id1);
            id_2 = Long.parseLong(id2);
        } catch (Exception ex) {
            showErrorMessage(null, "Ids not valid!");
        }
        socialNetwork.createFriendshipRequest(id_1, id_2);

        idFirstUser.clear();
        idSecondUser.clear();

        initApp(socialNetwork.getUsers());
    }


    public void acceptFriendRequest(MouseEvent mouseEvent) {
        if (listFriendshipsRequests.getSelectionModel().getSelectedItems() != null) {
            Friendship friendship = listFriendshipsRequests.getSelectionModel().getSelectedItem();
            socialNetwork.manageFriendRequest(friendship, FriendshipRequest.APPROVED);
            initApp(socialNetwork.getUsers());
        }
        initApp(socialNetwork.getUsers());
    }

    public void declineFriendRequest(MouseEvent mouseEvent) {
        if (listFriendshipsRequests.getSelectionModel().getSelectedItems() != null) {
            Friendship friendship = listFriendshipsRequests.getSelectionModel().getSelectedItem();
            socialNetwork.manageFriendRequest(friendship, FriendshipRequest.REJECTED);
            initApp(socialNetwork.getUsers());
        }
        initApp(socialNetwork.getUsers());
    }

    public void deleteFriendshipRequest(MouseEvent mouseEvent) {
        if (listFriendshipsRequests.getSelectionModel().getSelectedItems() != null) {
            Friendship friendship = listFriendshipsRequests.getSelectionModel().getSelectedItem();
            if (friendship.getFriendshipRequestStatus() == FriendshipRequest.REJECTED) {
                socialNetwork.removeFriendship(friendship.getIdUser1(), friendship.getIdUser2());
                initApp(socialNetwork.getUsers());
            } else showErrorMessage(null, "The request must be REJECTED in order to delete it!");
        }
        initApp(socialNetwork.getUsers());
    }
}
