package map.toysocialnetwork;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Modality;
import javafx.stage.Stage;
import map.toysocialnetwork.controller.MessageUser;
import map.toysocialnetwork.domain.Tuple;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.repository.database.UserDBRepository;
import map.toysocialnetwork.service.SocialNetwork;
import map.toysocialnetwork.utils.Observer;
import map.toysocialnetwork.utils.events.UserEvent;

import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class UsersController implements Observer<UserEvent> {

    SocialNetwork socialNetwork;
    ObservableList<User> model = FXCollections.observableArrayList();

    @FXML
    TableView<User> tableView;

    @FXML
    TableColumn<User, Long> tableUserId;

    @FXML
    TableColumn<User, String> tableUserFirstName;

    @FXML
    TableColumn<User, String> tableUserLastName;

    @FXML
    public void initialize() {
        tableUserId.setCellValueFactory(new PropertyValueFactory<User, Long>("id"));
        tableUserFirstName.setCellValueFactory(new PropertyValueFactory<User, String>("firstName"));
        tableUserLastName.setCellValueFactory(new PropertyValueFactory<User, String>("lastName"));
        tableView.setItems(model);
    }

    @FXML
    public void handleAddUser(ActionEvent ev) {
        showAddUserEditDialog(null);
    }

    @FXML
    public void handleDeleteUser(ActionEvent ev) {
        User selectedUser = tableView.getSelectionModel().getSelectedItem();
        if (selectedUser != null) {
            User userToDelete = socialNetwork.removeUser(selectedUser.getId());
            if (userToDelete != null) {
                MessageUser.showMessage(null, Alert.AlertType.INFORMATION,
                        "Delete", "The user ( " + userToDelete.getId()
                                + " " + userToDelete.getFirstName() + " " + userToDelete.getLastName()
                                + " ) was removed!");
            }

        } else MessageUser.showErrorMessage(null, "Select an User to delete!");


    }

    @FXML
    public void handleUpdateButton(ActionEvent ev) {

        User userToUpdate = tableView.getSelectionModel().getSelectedItem();
        if (userToUpdate != null) {
            socialNetwork.removeUser(userToUpdate.getId());
            showAddUserEditDialog(null);
        } else MessageUser.showErrorMessage(null, "Select an User to update!");
    }

    private void showAddUserEditDialog(User user) {
        try {
            FXMLLoader loader = new FXMLLoader(UsersController.class.getResource("views/add-user.fxml"));

            AnchorPane root = (AnchorPane) loader.load();

            Stage dialogStage = new Stage();
            dialogStage.setTitle("Add User");
            dialogStage.initModality(Modality.WINDOW_MODAL);

            Scene scene = new Scene(root);
            dialogStage.setScene(scene);

            AddUserController addUserController = ((FXMLLoader) loader).getController();
            addUserController.setService(socialNetwork, dialogStage, user);

            dialogStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void setSocialNetwork(SocialNetwork sn) {
        socialNetwork = sn;
        socialNetwork.addObserver(this);
        initModel();
    }

    private void initModel() {
        Iterable<User> users = socialNetwork.getUsers();
        List<User> usersList = StreamSupport.stream(users.spliterator(), false)
                .collect(Collectors.toList());
        model.setAll(usersList);
    }

    @Override
    public void update(UserEvent userEvent) {
        initModel();
    }
}
