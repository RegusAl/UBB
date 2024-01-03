package map.toysocialnetwork.service;

import map.toysocialnetwork.domain.Friendship;
import map.toysocialnetwork.domain.Message;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.domain.validators.ValidationException;
import map.toysocialnetwork.enums.FriendshipRequest;
import map.toysocialnetwork.repository.database.FriendshipDBRepository;
import map.toysocialnetwork.repository.database.MessagesDBRepository;
import map.toysocialnetwork.repository.pagination.Page;
import map.toysocialnetwork.repository.pagination.Pageable;
import map.toysocialnetwork.repository.pagination.PagingRepository;


import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;

import static map.toysocialnetwork.controller.MessageUser.showErrorMessage;

public class SocialNetwork {

    private final PagingRepository<Long, User> repositoryUser;
    private final PagingRepository<Long, Friendship> repositoryFriendship;

    private final MessagesDBRepository messagesDBRepository;


    public SocialNetwork(PagingRepository<Long, User> repositoryUser, PagingRepository<Long, Friendship> repositoryFriendship, MessagesDBRepository messagesDBRepository) {
        this.repositoryUser = repositoryUser;
        this.repositoryFriendship = repositoryFriendship;
        this.messagesDBRepository = messagesDBRepository;
    }

    /**
     * @return all Users from the social network
     */
    public Iterable<User> getUsers() {
        return repositoryUser.findAll();
    }

    /**
     * @param id Id of the user that needs to be found
     * @return User
     */
    public User findUser(Long id) {
        return repositoryUser.findOne(id).orElseThrow(() -> new ValidationException("User doesn't exist!"));
    }


    /**
     * @param user Adds the user to the map.repository
     */
    public User addUser(User user) {
        if (user.getFirstName().isEmpty() || user.getLastName().isEmpty()) {
            throw new ValidationException("User is invalid!");
        }
        repositoryUser.save(user);
        return user;
    }

    /**
     * @return All friendships from map.repository
     */
    public Iterable<Friendship> getFriendships() {
        return repositoryFriendship.findAll();
    }

    public List<User> getListFriends(User user) {
        List<User> friends = new ArrayList<>();
        getFriendships().forEach(friendship -> {
            if (friendship.getIdUser1().equals(user.getId())) {
                friends.add(findUser(friendship.getIdUser2()));
            } else if (friendship.getIdUser2().equals(user.getId())) {
                friends.add(findUser(friendship.getIdUser1()));
            }
        });
        return friends;
    }


    /**
     * @param id - id of the user that needs to be removed
     * @return user
     */
    public User removeUser(Long id) {
        User u = null;
        try {
            u = repositoryUser.findOne(id).orElseThrow(() -> new ValidationException("User doesn't exist!"));
            if (u == null) {
                throw new IllegalArgumentException("User doesn't exist!");
            }
            repositoryUser.delete(id);

        } catch (IllegalArgumentException e) {
            System.out.println("Invalid user! ");
        } catch (ValidationException v) {
            System.out.println();
        }
        return u;
    }


    public Long getNewFriendshipId() {
        Long id = 0L;
        for (Friendship f : repositoryFriendship.findAll()) {
            id = f.getId();
        }
        id++;
        return id;
    }

    public void addFriendship(Friendship friendship) {
        if (getFriendships() != null) {
            getFriendships().forEach(f -> {
                if (f.getIdUser1().equals(friendship.getIdUser1()) && f.getIdUser2().equals(friendship.getIdUser2())) {
                    throw new ValidationException("The friendship already exist! ");
                }
            });
            if (repositoryUser.findOne(friendship.getIdUser1()).isEmpty() || repositoryUser.findOne(friendship.getIdUser2()).isEmpty()) {
                throw new ValidationException("User doesn't exist! ");
            }
            if (friendship.getIdUser1().equals(friendship.getIdUser2()))
                throw new ValidationException("IDs can't be the same!!! ");
        }

        friendship.setId(getNewFriendshipId());
        repositoryFriendship.save(friendship);

    }

    public void removeFriendship(Long id1, Long id2) {
        Long id = 0L;
        for (Friendship f : repositoryFriendship.findAll()) {
            if ((f.getIdUser1().equals(id1) && f.getIdUser2().equals(id2)) || (f.getIdUser1().equals(id2) && f.getIdUser2().equals(id1)))
                id = f.getId();
        }
        if (id == 0L)
            throw new IllegalArgumentException("The friendship doesn't exist!");
        repositoryFriendship.delete(id);
    }

    public void createFriendshipRequest(Long id1, Long id2) {
        Friendship friendship = new Friendship(id1, id2, LocalDateTime.now());
        addFriendship(friendship);
    }

    public void manageFriendRequest(Friendship friendship, FriendshipRequest friendshipRequest) {
        try {
            if (!repositoryFriendship.findOne(friendship.getId()).isPresent()) {
                throw new Exception("Friendship doesn't exist!");
            } else if (friendship.getFriendshipRequestStatus() != FriendshipRequest.PENDING) {
                showErrorMessage(null, "The request must be PENDING in order to APPROVE/DECLINE it");
                throw new Exception("Friendship is not PENDING!");
            }
            friendship.setFriendshipRequestStatus(friendshipRequest);
            repositoryFriendship.update(friendship);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // Messages

    public boolean addMessage(Long id_from, Long id_to, String message) {
        try {
            User from = findUser(id_from);
            User to = findUser(id_to);

            Message msg = new Message(from, Collections.singletonList(to), message);
            messagesDBRepository.save(msg);

            List<Message> messagesBetweenUsers = getMessages(id_to, id_from);
            if (messagesBetweenUsers.size() > 1) {
                Message oldReplyMessage = messagesBetweenUsers.get(messagesBetweenUsers.size() - 2);
                Message newReplyMessage = messagesBetweenUsers.get(messagesBetweenUsers.size() - 1);
                oldReplyMessage.setReply(newReplyMessage);
                messagesDBRepository.update(oldReplyMessage);
            }

            return true;
        } catch (ValidationException ve) {
            System.out.println("eroare user");
        } catch (Exception ex) {
            System.out.println("eroare creare mesaj!");
        }
        return false;
    }

    public ArrayList<Message> getMessages(Long id1, Long id2) {
        User user1 = findUser(id1);
        User user2 = findUser(id2);

        Collection<Message> messages = (Collection<Message>) messagesDBRepository.findAll();
//        System.out.println(messages);
        return messages.stream()
                .filter(msg -> ((msg.getFrom().getId().equals(id1)) && msg.getTo().get(0).getId().equals(id2)) ||
                        (msg.getFrom().getId().equals(id2) && msg.getTo().get(0).getId().equals(id1)))
                .sorted(Comparator.comparing(Message::getData))
                .collect(Collectors.toCollection(ArrayList::new));


    }

    public Page<User> findAllUsers(Pageable pageable) {
        return repositoryUser.findall(pageable);
    }


    public Page<Friendship> findAllFriendships(Pageable pageable) {
        return repositoryFriendship.findall(pageable);
    }
}
