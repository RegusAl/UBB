package map.toysocialnetwork;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import map.toysocialnetwork.domain.Friendship;
import map.toysocialnetwork.domain.Message;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.domain.validators.UserValidator;
import map.toysocialnetwork.domain.validators.ValidationException;
import map.toysocialnetwork.enums.FriendshipRequest;
import map.toysocialnetwork.repository.pagination.Page;
import map.toysocialnetwork.repository.pagination.Pageable;
import map.toysocialnetwork.service.SocialNetwork;

import java.lang.reflect.InvocationTargetException;
import java.net.URL;
import java.util.ResourceBundle;

import static map.toysocialnetwork.controller.MessageUser.showErrorMessage;

public class Controller implements Initializable {



    SocialNetwork socialNetwork;

    UserValidator userValidator;

    // Observable Lists

    ObservableList<User> userObs = FXCollections.observableArrayList();
    ObservableList<Friendship> friendshipObs = FXCollections.observableArrayList();

    ObservableList<Friendship> friendshipsRequestsObs = FXCollections.observableArrayList();

    ObservableList<Message> messagesObs = FXCollections.observableArrayList();

    // Pagination vars

    private int currentPageUsers = 0;
    private int pageSizeUsers = 5;

    private int currentPageFriendships = 0;
    private int pageSizeFriendships = 5;

    // User Window

    public Button previousBtnUsers;
    public Button firstPageBtnUsers;
    public Button nextBtnUsers;
    public Button lastPageBtnUsers;

    public TextField numberUsersOnPage;

    @FXML
    private ListView<User> listUsers;

    @FXML
    public TextField textFieldId;

    @FXML
    public TextField textFieldFirstName;

    @FXML
    public TextField textFieldLastName;

    // Friendship Window

    public Button firstPageBtnFriendships;
    public Button previousBtnPageFriendships;
    public Button nextBtnPageFriendships;
    public Button lastBtnPageFriendships;
    public TextField numberFriendshipsOnPage;

    @FXML
    private ListView<Friendship> listFriendships;

    // Friendships Requests Window

    @FXML
    private ListView<Friendship> listFriendshipsRequests;

    @FXML
    private TextField idFirstUser;

    @FXML
    private TextField idSecondUser;

    // Messages TAB

    @FXML
    private ListView<Message> listMessages;


    @FXML
    private TextField sendMessageId1;

    @FXML
    private TextField sendMessageId2;

    @FXML
    private TextArea message;

    public ChoiceBox<User> choiceboxId1;

    public ChoiceBox<User> choiceboxId2;


    public void setSocialNetwork(SocialNetwork sn) {
        socialNetwork = sn;
    }


    @Override
    public void initialize(URL location, ResourceBundle resources) {

        choiceboxId1.setItems(userObs);
        choiceboxId2.setItems(userObs);
        listUsers.setItems(userObs);
        listFriendships.setItems(friendshipObs);
        listFriendshipsRequests.setItems(friendshipsRequestsObs);
    }

    public void initApp() {
        listUsers.getItems().clear();
        listFriendships.getItems().clear();
        listFriendshipsRequests.getItems().clear();

        // Users

        Page<User> pageUsers = socialNetwork.findAllUsers(new Pageable(currentPageUsers, pageSizeUsers));

        int maxPageUsers = (int) Math.ceil((double) pageUsers.getTotalElementsCount() / pageSizeUsers) - 1;
        if (currentPageUsers > maxPageUsers) {
            currentPageUsers = maxPageUsers;
            pageUsers = socialNetwork.findAllUsers(new Pageable(currentPageUsers, pageSizeUsers));
        }

        int totalNumberOfElementsUsers = pageUsers.getTotalElementsCount();

        previousBtnUsers.setDisable(currentPageUsers == 0);
        firstPageBtnUsers.setDisable(currentPageUsers == 0);
        nextBtnUsers.setDisable((currentPageUsers + 1) * pageSizeUsers >= totalNumberOfElementsUsers);
        lastPageBtnUsers.setDisable((currentPageUsers + 1) * pageSizeUsers >= totalNumberOfElementsUsers);

        for (User user : pageUsers.getElementsOnPage()) {
            userObs.add(user);
        }

        listUsers.setItems(userObs);

        // Friendships

        Page<Friendship> pageFriendships = socialNetwork.findAllFriendships(new Pageable(currentPageFriendships, pageSizeFriendships));

        int maxPageFriendships = (int) Math.ceil((double) pageFriendships.getTotalElementsCount() / pageSizeFriendships) - 1;
        if (currentPageFriendships > maxPageFriendships) {
            currentPageFriendships = maxPageFriendships;
            pageFriendships = socialNetwork.findAllFriendships(new Pageable(currentPageFriendships, pageSizeFriendships));
        }

        int totalNumberOfElementsFriendships = pageFriendships.getTotalElementsCount();

        previousBtnPageFriendships.setDisable(currentPageFriendships == 0);
        firstPageBtnFriendships.setDisable(currentPageFriendships == 0);
        nextBtnPageFriendships.setDisable((currentPageFriendships + 1) * pageSizeFriendships >= totalNumberOfElementsFriendships);
        lastBtnPageFriendships.setDisable((currentPageFriendships + 1) * pageSizeFriendships >= totalNumberOfElementsFriendships);


        for (Friendship friendship : pageFriendships.getElementsOnPage()) {
                friendshipObs.add(friendship);
        }

        listFriendships.setItems(friendshipObs);

        // Friendships requests

        for(Friendship friendshipRequest : socialNetwork.getFriendships()) {
            friendshipsRequestsObs.add(friendshipRequest);
        }

        listFriendshipsRequests.setItems(friendshipsRequestsObs);

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
            showErrorMessage(null, "User can't be added!");
        } catch (Exception e) {
//            System.out.println("id is not number");
            showErrorMessage(null, "User can't be added!");
            textFieldId.clear();
            textFieldFirstName.clear();
            textFieldLastName.clear();
        }

        textFieldId.clear();
        textFieldFirstName.clear();
        textFieldLastName.clear();

        initApp();
    }

    public void deleteUser(MouseEvent mouseEvent) {
        if (listUsers.getSelectionModel().getSelectedItems() != null) {
            User user = listUsers.getSelectionModel().getSelectedItem();
            socialNetwork.removeUser(user.getId());

            initApp();
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
            showErrorMessage(null, "Can't update because User is invalid!");
        } catch (Exception e) {
            System.out.println("Id is not number");
            showErrorMessage(null, "User can't be updated!");
            textFieldId.clear();
            textFieldFirstName.clear();
            textFieldLastName.clear();
        }

        textFieldId.clear();
        textFieldFirstName.clear();
        textFieldLastName.clear();

        initApp();
    }

    public void deleteFriendship(MouseEvent mouseEvent) {
        try {
            if (listFriendships.getSelectionModel().getSelectedItems() != null) {
                Friendship friendship = listFriendships.getSelectionModel().getSelectedItem();
                socialNetwork.removeFriendship(friendship.getIdUser1(), friendship.getIdUser2());
                initApp();
            }
        } catch (Exception ex) {
            showErrorMessage(null, "Select a friend request from table!");
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

        initApp();
    }


    public void acceptFriendRequest(MouseEvent mouseEvent) {
        if (listFriendshipsRequests.getSelectionModel().getSelectedItems() != null) {
            Friendship friendship = listFriendshipsRequests.getSelectionModel().getSelectedItem();
            socialNetwork.manageFriendRequest(friendship, FriendshipRequest.APPROVED);
            initApp();
        } else showErrorMessage(null, "The request must be PENDING in order to APPROVE/DECLINE it");
        initApp();
    }

    public void declineFriendRequest(MouseEvent mouseEvent) {
        if (listFriendshipsRequests.getSelectionModel().getSelectedItems() != null) {
            Friendship friendship = listFriendshipsRequests.getSelectionModel().getSelectedItem();
            socialNetwork.manageFriendRequest(friendship, FriendshipRequest.REJECTED);
            initApp();
        }
        initApp();
    }

    public void deleteFriendshipRequest(MouseEvent mouseEvent) {
        if (listFriendshipsRequests.getSelectionModel().getSelectedItems() != null) {
            Friendship friendship = listFriendshipsRequests.getSelectionModel().getSelectedItem();
            if (friendship.getFriendshipRequestStatus() == FriendshipRequest.REJECTED) {
                socialNetwork.removeFriendship(friendship.getIdUser1(), friendship.getIdUser2());
                initApp();
            } else showErrorMessage(null, "The request must be REJECTED in order to delete it!");
        } else showErrorMessage(null, "Select a friend request from table!");
        initApp();
    }

    public void loadListMessages(Long id1, Long id2) {
        listMessages.getItems().clear();
        messagesObs.clear();
        for (Message msg : socialNetwork.getMessages(id1, id2)) {
            messagesObs.add(msg);
        }
        if (messagesObs.isEmpty()) {
            showErrorMessage(null, "There are no messages!");
        }
//        System.out.println(listMessages.getItems());
        listMessages.setItems(messagesObs);
    }

    public void searchMessages(MouseEvent mouseEvent) {

        Long id1 = choiceboxId1.getSelectionModel().getSelectedItem().getId();
        Long id2 = choiceboxId2.getSelectionModel().getSelectedItem().getId();

        loadListMessages(id1, id2);
    }

    public void sendMessage(MouseEvent mouseEvent) {

        Long idFrom = choiceboxId1.getSelectionModel().getSelectedItem().getId();
        Long idTo = choiceboxId2.getSelectionModel().getSelectedItem().getId();

        String msg = message.getText();

        socialNetwork.addMessage(idFrom, idTo, msg);
        loadListMessages(idFrom, idTo);

        message.clear();
    }

    // Pagination Users

    public void onPreviousPageUsers(MouseEvent mouseEvent) {
        currentPageUsers--;
        initApp();
    }

    public void onFirstPageUsers(MouseEvent mouseEvent) {
        currentPageUsers = 0;
        initApp();
    }

    public void onNextPageUsers(MouseEvent mouseEvent) {
        currentPageUsers++;
        initApp();
    }

    public void onLastPageUsers(MouseEvent mouseEvent) {
        Page<User> userPage = socialNetwork.findAllUsers(new Pageable(currentPageUsers, pageSizeUsers));
        currentPageUsers = (int) Math.ceil((double) userPage.getTotalElementsCount() / pageSizeUsers) - 1;
        initApp();
    }

    public void setNumberOfUsersOnPage(KeyEvent keyEvent) {
        if (keyEvent.getCode().equals(KeyCode.ENTER)) {
            try {
                pageSizeUsers = Integer.parseInt(numberUsersOnPage.getText());
            } catch (Exception e) {
                showErrorMessage(null, "Wrong input!");
            }
            initApp();
        }
    }

    public void onFirstPageFriendships(MouseEvent mouseEvent) {
        currentPageFriendships = 0;
        initApp();
    }

    public void onPreviousPageFriendships(MouseEvent mouseEvent) {
        currentPageFriendships--;
        initApp();
    }

    public void onNextPageFriendships(MouseEvent mouseEvent) {
        currentPageFriendships++;
        initApp();
    }

    public void onLastPageFriendships(MouseEvent mouseEvent) {
        Page<Friendship> friendshipPage = socialNetwork.findAllFriendships(new Pageable(currentPageFriendships, pageSizeFriendships));
        currentPageFriendships = (int) Math.ceil((double) friendshipPage.getTotalElementsCount() / pageSizeFriendships) - 1;
        initApp();
    }

    public void setNumberOfFriendshipsOnPage(KeyEvent keyEvent) {
        if (keyEvent.getCode().equals(KeyCode.ENTER)) {
            try {
                pageSizeFriendships = Integer.parseInt(numberFriendshipsOnPage.getText());
            } catch (Exception e) {
                showErrorMessage(null, "Wrong input!");
            }
            initApp();
        }
    }
}
