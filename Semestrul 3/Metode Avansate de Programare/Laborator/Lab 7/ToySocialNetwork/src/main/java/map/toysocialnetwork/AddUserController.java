package map.toysocialnetwork;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.domain.validators.ValidationException;
import map.toysocialnetwork.service.SocialNetwork;

public class AddUserController {

    @FXML
    private TextField textFieldId;

    @FXML
    private TextField textFieldLastName;

    @FXML
    private TextField textFieldFirstName;

    private SocialNetwork service;
    Stage dialogStage;
    User user;

    @FXML
    private void initialize() {

    }


    public void setService(SocialNetwork socialNetwork, Stage dialogStage, User user) {
        this.service = socialNetwork;
        this.dialogStage = dialogStage;
        this.user = user;
        if(user != null) {
            setFields(user);
        }
    }

    @FXML
    public void handleSave() {
        String id = textFieldId.getText();
        String firstName = textFieldFirstName.getText();
        String lastName = textFieldLastName.getText();
        User user = new User(Long.parseLong(id), firstName, lastName);
        if(null == this.user)
            saveUser(user);
        else
            updateUser(user);
    }

    private void saveUser(User user) {
        try {
            User newUser = this.service.addUser(user);
            if(newUser == null)
                dialogStage.close();
        } catch (ValidationException e) {

        }
        dialogStage.close();
    }

    private void updateUser(User user) {

    }

    private void setFields(User user) {
        textFieldId.setText(user.getId().toString());
        textFieldFirstName.setText(user.getFirstName());
        textFieldLastName.setText(user.getLastName());
    }

    @FXML
    public void handleCancel() {
        dialogStage.close();
    }


}
