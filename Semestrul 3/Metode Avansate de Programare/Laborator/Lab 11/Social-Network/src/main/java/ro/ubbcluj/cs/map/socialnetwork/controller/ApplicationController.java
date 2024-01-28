package ro.ubbcluj.cs.map.socialnetwork.controller;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import ro.ubbcluj.cs.map.socialnetwork.domain.FriendRequest;
import ro.ubbcluj.cs.map.socialnetwork.domain.Friendship;
import ro.ubbcluj.cs.map.socialnetwork.domain.Message;
import ro.ubbcluj.cs.map.socialnetwork.domain.User;
import ro.ubbcluj.cs.map.socialnetwork.repository.Page;
import ro.ubbcluj.cs.map.socialnetwork.repository.Pageable;
import ro.ubbcluj.cs.map.socialnetwork.service.Service;

import java.net.URL;
import java.util.*;

public class ApplicationController implements Initializable {

    public Label userProfile;
    private Service service;

    private User userLogged;

    private final ObservableList<User> usersObs = FXCollections.observableArrayList();
    private final ObservableList<Friendship> friendshipsObs = FXCollections.observableArrayList();
    private final ObservableList<Friendship> friendRequestsObs = FXCollections.observableArrayList();
    private final ObservableList<Message> messagesObs = FXCollections.observableArrayList();


    // Pagination variables
    private int currentPageUsers = 0;
    private int pageSizeUsers = 5;

    private int currentPageFriendships = 0;
    private int pageSizeFriendships = 5;

    private int currentPageFriendRequests = 0;
    private int pageSizeFriendRequests = 5;

    private int currentPageMessages = 0;
    private int pageSizeMessages = 5;


    private String emailTo = "";


    // Friendships Window
    @FXML
    private Button nextBtnFriendships;
    @FXML
    private Button previousBtnFriendships;
    @FXML
    private Button lastPageBtnFriendships;
    @FXML
    private Button firstPageBtnFriendships;
    @FXML
    private TextField noElementsOnPageFriendships;
    @FXML
    private Label pageNumberFriendships;
    @FXML
    private ListView<Friendship> listOfFriendships;

    // Friend Request Window
    @FXML
    private Button nextBtnFriendRequests;
    @FXML
    private Button previousBtnFriendRequests;
    @FXML
    private Button lastPageBtnFriendRequests;
    @FXML
    private Button firstPageBtnFriendRequests;
    @FXML
    private TextField noElementsOnPageFriendRequests;
    @FXML
    private Label pageNumberFriendRequests;
    @FXML
    private ListView<Friendship> listOfFriendRequests;
    @FXML
    private TextField friendRequestEmail;

    // Message window
    @FXML
    private Button nextBtnMessages;
    @FXML
    private Button previousBtnMessages;
    @FXML
    private Button lastPageBtnMessages;
    @FXML
    private Button firstPageBtnMessages;
    @FXML
    private TextField noElementsOnPageMessages;
    @FXML
    private Label pageNumberMessages;
    @FXML
    private ListView<Message> listOfMessages;
    @FXML
    private TextField message;
    @FXML
    private TextField sendEmailTo;
    @FXML
    private TextField showMessagesEmail;


    public void setService(Service service) {
        this.service = service;
    }

    public void setUserLogged(User userLogged) {
        this.userLogged = userLogged;
        userProfile.setText(userLogged.getEmail() + " \n" + userLogged.getFirstName() + " \n" + userLogged.getLastName());

    }

    public void initApp() {
        listOfFriendships.getItems().clear();
        listOfFriendRequests.getItems().clear();
        listOfMessages.getItems().clear();

//        userProfile.setText(userLogged.getEmail() + " \n" + userLogged.getFirstName() + " \n" + userLogged.getLastName());

        // Friendships
        Page<Friendship> pageFriendships = service.findAllUserFriends(new Pageable(currentPageFriendships, pageSizeFriendships), this.userLogged);

        int maxPageFriendships = (int) Math.ceil((double) pageFriendships.getTotalElementCount() / pageSizeFriendships) - 1;
        if (maxPageFriendships == -1) maxPageFriendships = 0;
        if (currentPageFriendships > maxPageFriendships) {
            currentPageFriendships = maxPageFriendships;
            pageFriendships = service.findAllFriendships(new Pageable(currentPageFriendships, pageSizeFriendships));
        }

        int totalNumberOfElementsFriendships = pageFriendships.getTotalElementCount();

        previousBtnFriendships.setDisable(currentPageFriendships == 0);
        firstPageBtnFriendships.setDisable(currentPageFriendships == 0);
        nextBtnFriendships.setDisable((currentPageFriendships + 1) * pageSizeFriendships >= totalNumberOfElementsFriendships);
        lastPageBtnFriendships.setDisable((currentPageFriendships + 1) * pageSizeFriendships >= totalNumberOfElementsFriendships);


        for (Friendship friendship : pageFriendships.getElementsOnPage()) {
            friendshipsObs.add(friendship);
        }
        listOfFriendships.setItems(friendshipsObs);

        pageNumberFriendships.setText((currentPageFriendships + 1) + "/" + (maxPageFriendships + 1));

        // Friend Requests
        Page<Friendship> pageFriendRequests = service.findAllUserFriendRequests(new Pageable(currentPageFriendRequests, pageSizeFriendRequests), this.userLogged);

        int maxPageFriendRequests = (int) Math.ceil((double) pageFriendRequests.getTotalElementCount() / pageSizeFriendRequests) - 1;
        if (maxPageFriendRequests == -1) maxPageFriendRequests = 0;
        if (currentPageFriendRequests > maxPageFriendRequests ) {
            currentPageFriendRequests = maxPageFriendRequests;
            pageFriendRequests = service.findAllFriendRequests(new Pageable(currentPageFriendRequests, pageSizeFriendRequests));
        }

        int totalNumberOfElementsFriendRequests = pageFriendRequests.getTotalElementCount();

        previousBtnFriendRequests.setDisable(currentPageFriendRequests == 0);
        firstPageBtnFriendRequests.setDisable(currentPageFriendRequests == 0);
        nextBtnFriendRequests.setDisable((currentPageFriendRequests + 1) * pageSizeFriendRequests >= totalNumberOfElementsFriendRequests);
        lastPageBtnFriendRequests.setDisable((currentPageFriendRequests + 1) * pageSizeFriendRequests >= totalNumberOfElementsFriendRequests);

        for (Friendship friendship : pageFriendRequests.getElementsOnPage()) {
            friendRequestsObs.add(friendship);
        }
        listOfFriendRequests.setItems(friendRequestsObs);

        pageNumberFriendRequests.setText((currentPageFriendRequests + 1) + "/" + (maxPageFriendRequests + 1));

        // Messages
        Page<Message> pageMessages = service.findAllMessages(new Pageable(currentPageMessages, pageSizeMessages), this.userLogged.getEmail(), this.emailTo);

        if (pageMessages.getTotalElementCount() != 0) {
            int maxPageMessages = (int) Math.ceil((double) pageMessages.getTotalElementCount() / pageSizeMessages) - 1;
            if (maxPageMessages == -1) maxPageMessages = 0;
            if (currentPageMessages > maxPageMessages) {
                currentPageMessages = maxPageMessages;
                pageMessages = service.findAllMessages(new Pageable(currentPageMessages, pageSizeMessages), this.userLogged.getEmail(), this.emailTo);
            }
            int totalNumberOfElementsMessages = pageMessages.getTotalElementCount();

            previousBtnMessages.setDisable(currentPageMessages == 0);
            firstPageBtnMessages.setDisable(currentPageMessages == 0);
            nextBtnMessages.setDisable((currentPageMessages + 1) * pageSizeMessages >= totalNumberOfElementsMessages);
            lastPageBtnMessages.setDisable((currentPageMessages + 1) * pageSizeMessages >= totalNumberOfElementsMessages);

            messagesObs.clear();
            for (Message msg : pageMessages.getElementsOnPage()) {
                messagesObs.add(msg);
            }

            listOfMessages.setItems(messagesObs);

            pageNumberMessages.setText((currentPageMessages + 1) + "/" + (maxPageMessages + 1));
        }
    }

    public void deleteFriendship(MouseEvent mouseEvent) {
        if (listOfFriendships.getSelectionModel().getSelectedItem() != null) {
            Friendship friendship = listOfFriendships.getSelectionModel().getSelectedItem();
            service.getFriendshipRepo().delete(friendship.getId());
            initApp();
        }
    }

    public void onPreviousFriendships(MouseEvent mouseEvent) {
        currentPageFriendships--;
        initApp();
    }

    public void onNextFriendships(MouseEvent mouseEvent) {
        currentPageFriendships++;
        initApp();
    }

    public void onFirstFriendships(MouseEvent mouseEvent) {
        currentPageFriendships = 0;
        initApp();
    }

    public void onLastFriendships(MouseEvent mouseEvent) {
        Page<Friendship> pageFriendships = service.findAllFriendships(new Pageable(currentPageFriendships, pageSizeFriendships));
        currentPageFriendships = (int) Math.ceil((double) pageFriendships.getTotalElementCount() / pageSizeFriendships) - 1;
        initApp();
    }

    public void setNoElementsOnPageFriendships(KeyEvent key) {
        if (key.getCode().equals(KeyCode.ENTER)) {
            try {
                if (!Objects.equals(noElementsOnPageFriendships.getText(), "0"))
                    pageSizeFriendships = Integer.parseInt(noElementsOnPageFriendships.getText());
            } catch (Exception e) {
                Alert errorAlert = new Alert(Alert.AlertType.ERROR);
                errorAlert.setHeaderText("!!!");
                errorAlert.setContentText("Something wrong");
                errorAlert.showAndWait();
            }
            initApp();
        }
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        listOfFriendships.setItems(friendshipsObs);
        listOfFriendRequests.setItems(friendRequestsObs);
    }

    public void createFriendRequest(MouseEvent mouseEvent) {
        String email = friendRequestEmail.getText();

        if (!service.createFriendRequest(email, this.userLogged.getEmail())) {
            Alert errorAlert = new Alert(Alert.AlertType.WARNING);
            errorAlert.setHeaderText("!!!");
            errorAlert.setContentText("Something went wrong");
            errorAlert.showAndWait();
        }

        friendRequestEmail.clear();
        initApp();
    }

    public void acceptFriendRequest(MouseEvent mouseEvent) {
        if (listOfFriendRequests.getSelectionModel().getSelectedItem() != null) {
            Friendship friendship = listOfFriendRequests.getSelectionModel().getSelectedItem();
            if (!Objects.equals(friendship.getUser1Id(), this.userLogged.getId())) {
                service.respondFriendRequest(friendship, FriendRequest.ACCEPTED);
                initApp();
            }
        }
        initApp();
    }

    public void rejectFriendRequest(MouseEvent mouseEvent) {
        if (listOfFriendRequests.getSelectionModel().getSelectedItem() != null) {
            Friendship friendship = listOfFriendRequests.getSelectionModel().getSelectedItem();
            if (!Objects.equals(friendship.getUser1Id(), this.userLogged.getId())) {
                service.respondFriendRequest(friendship, FriendRequest.REJECTED);
                initApp();
            }
        }
        initApp();
    }

    public void deleteFriendRequest(MouseEvent mouseEvent) {
        if (listOfFriendRequests.getSelectionModel().getSelectedItem() != null) {
            Friendship friendship = listOfFriendRequests.getSelectionModel().getSelectedItem();
            service.getFriendshipRepo().delete(friendship.getId());
            initApp();
        }
    }

    public void onPreviousFriendRequests(MouseEvent mouseEvent) {
        currentPageFriendRequests--;
        initApp();
    }

    public void onNextFriendRequests(MouseEvent mouseEvent) {
        currentPageFriendRequests++;
        initApp();
    }

    public void setNoElementsOnPageFriendRequests(KeyEvent key) {
        if (key.getCode().equals(KeyCode.ENTER)) {
            try {
                pageSizeFriendRequests = Integer.parseInt(noElementsOnPageFriendRequests.getText());
            } catch (Exception e) {
                Alert errorAlert = new Alert(Alert.AlertType.ERROR);
                errorAlert.setHeaderText("!!!");
                errorAlert.setContentText("Something wrong");
                errorAlert.showAndWait();
            }
            initApp();
        }
    }

    public void onLastFriendRequests(MouseEvent mouseEvent) {
        Page<Friendship> pageFriendRequests = service.findAllFriendRequests(new Pageable(currentPageFriendRequests, pageSizeFriendRequests));
        currentPageFriendRequests = (int) Math.ceil((double) pageFriendRequests.getTotalElementCount() / pageSizeFriendRequests) - 1;
        initApp();
    }

    public void onFirstFriendRequests(MouseEvent mouseEvent) {
        currentPageFriendRequests = 0;
        initApp();
    }

    public void searchMessages(MouseEvent mouseEvent) {
        String email1 = showMessagesEmail.getText();
        String email2 = this.userLogged.getEmail();

        showMessagesEmail.clear();

        sendEmailTo.setText(email1);

        // loadListOfMessages(email1, email2);
        this.emailTo = email1;
        initApp();
    }

    public void sendMessage(MouseEvent mouseEvent) {
        String emailFrom = this.userLogged.getEmail();
        String emailTo = sendEmailTo.getText();
        List<String> toUsers = new ArrayList<>(Arrays.asList(emailTo.split(" ")));
        String msg = message.getText();

        if (!service.addMessage(emailFrom, toUsers, msg)) {
            Alert errorAlert = new Alert(Alert.AlertType.ERROR);
            errorAlert.setHeaderText("!!!");
            errorAlert.setContentText("Something wrong");
            errorAlert.showAndWait();
        } else {
            // loadListOfMessages(emailFrom, toUsers.get(0));
            this.emailTo = toUsers.get(0);
            onLastMessages(mouseEvent);
            initApp();
        }

        message.clear();
    }

    public void replyMessage(MouseEvent mouseEvent) {
        if (listOfMessages.getSelectionModel().getSelectedItem() != null) {
            Message msg = listOfMessages.getSelectionModel().getSelectedItem();

            String emailFrom = this.userLogged.getEmail();
            String emailTo = sendEmailTo.getText();
            List<String> toUsers = new ArrayList<>(Collections.singletonList(emailTo));
            String replyText = message.getText();

            if (!service.addMessage(emailFrom, toUsers, replyText, msg)) {
                Alert errorAlert = new Alert(Alert.AlertType.ERROR);
                errorAlert.setHeaderText("!!!");
                errorAlert.setContentText("Something wrong");
                errorAlert.showAndWait();
            } else {
                // loadListOfMessages(this.userLogged.getEmail(), toUsers.get(0));
                this.emailTo = toUsers.get(0);
                initApp();
            }

            message.clear();
        }
    }

    public void onPreviousMessages(MouseEvent mouseEvent) {
        currentPageMessages--;
        initApp();
    }

    public void onNextMessages(MouseEvent mouseEvent) {
        currentPageMessages++;
        initApp();
    }

    public void onFirstMessages(MouseEvent mouseEvent) {
        currentPageMessages = 0;
        initApp();
    }

    public void onLastMessages(MouseEvent mouseEvent) {
        Page<Message> pageMessages = service.findAllMessages(new Pageable(currentPageMessages, pageSizeMessages), this.userLogged.getEmail(), emailTo);
        currentPageMessages = (int) Math.ceil((double) pageMessages.getTotalElementCount() / pageSizeMessages) - 1;
        initApp();
    }

    public void setNoElementsOnPageMessages(KeyEvent key) {
        if (key.getCode().equals(KeyCode.ENTER)) {
            try {
                pageSizeMessages = Integer.parseInt(noElementsOnPageMessages.getText());
            } catch (Exception e) {
                Alert errorAlert = new Alert(Alert.AlertType.ERROR);
                errorAlert.setHeaderText("!!!");
                errorAlert.setContentText("Something wrong");
                errorAlert.showAndWait();
            }
            initApp();
        }
    }

    public void loadListOfMessages(String emailFrom, String emailTo) {
        messagesObs.clear();
        for (Message msg : service.getMessagesBetweenTwoUsers(emailFrom, emailTo)) {
            messagesObs.add(msg);

        }
        if (messagesObs.isEmpty()) {
            Alert errorAlert = new Alert(Alert.AlertType.INFORMATION);
            errorAlert.setHeaderText(":((");
            errorAlert.setContentText("No messages");
            errorAlert.showAndWait();
        }

        listOfMessages.setItems(messagesObs);
    }
}
