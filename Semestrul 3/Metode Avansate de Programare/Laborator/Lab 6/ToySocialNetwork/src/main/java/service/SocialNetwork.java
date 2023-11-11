package service;

import domain.Friendship;
import domain.User;
import domain.validators.ValidationException;
import repository.database.FriendshipDBRepository;
import repository.database.UserDBRepository;

import java.util.*;

public class SocialNetwork {

    private final UserDBRepository repositoryUser;
    private final FriendshipDBRepository repositoryFriendship;

    public SocialNetwork(UserDBRepository repositoryUser, FriendshipDBRepository repositoryFriendship) {
        this.repositoryUser = repositoryUser;
        this.repositoryFriendship = repositoryFriendship;
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
     * @return id(Long)
     */
    public Long getNewUserId() {
        Long id = 0L;
        for (User u : repositoryUser.findAll()) {
            id = u.getId();
        }
        id++;
        return id;
    }

    /**
     * @param user Adds the user to the repository
     */
    public void addUser(User user) {
        user.setId(getNewUserId());
        repositoryUser.save(user);
    }

    /**
     * @return All friendships from repository
     */
    public Iterable<Friendship> getFriendships() {
        return repositoryFriendship.findAll();
    }

//    public void refreshFriends() {
//        repositoryFriendship.findAll().forEach(friendship -> {
//            User user1 = repositoryUser.findOne(friendship.getIdUser1()).orElseThrow(null);
//            User user2 = repositoryUser.findOne(friendship.getIdUser2()).orElseThrow(null);
//            user1.addFriend(user2);
//            user2.addFriend(user1);
//
//        });
//        repositoryUser.findAll().forEach(System.out::println);
//    }

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
            Vector<Long> toDelete = new Vector<>();
            getFriendships().forEach(friendship -> {
                if (friendship.getIdUser2().equals(id) || friendship.getIdUser1().equals(id)) {
                    toDelete.add(friendship.getId());
                }
            });
            toDelete.forEach(repositoryFriendship::delete);
            repositoryUser.delete(id);
            //            u.getFriends().forEach(friend -> friend.removeFriend(u));
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

//        assert user1 != null;
//        user1.removeFriend(user2);
//        assert user2 != null;
//        user2.removeFriend(user1);
    }
}
