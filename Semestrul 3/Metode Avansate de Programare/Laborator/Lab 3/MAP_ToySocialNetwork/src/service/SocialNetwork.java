package service;

import domain.Entity;
import domain.Friendship;
import domain.Tuple;
import domain.User;
import domain.validators.UserValidator;
import repository.InMemoryRepository;
import repository.Repository;

import java.util.List;
import java.util.Random;
import java.util.UUID;
import java.util.Vector;

public class SocialNetwork {

    private InMemoryRepository<Long, User> repositoryUser;
    private InMemoryRepository<Long, Friendship> repositoryFriendship;

    public SocialNetwork(InMemoryRepository<Long, User> repositoryUser, InMemoryRepository<Long, Friendship> repositoryFriendship) {
        this.repositoryUser = repositoryUser;
        this.repositoryFriendship = repositoryFriendship;
    }

    public Iterable<User> getUsers() {
        return repositoryUser.findAll();
    }

    public User findUser(Long id) {
        return repositoryUser.findOne(id);
    }

    public Long getNewUserId() {
        Long id = 0L;
        for (User u : repositoryUser.findAll()) {
            id = u.getId();
        }
        id++;
        return id;
    }

    public void addUser(User user) {
        user.setId(getNewUserId());
        repositoryUser.save(user);
    }

    public Iterable<Friendship> getFriendships() {
        return repositoryFriendship.findAll();
    }

    public void removeUser(Long id) {
        try {
            User u = repositoryUser.findOne(id);
            if (u == null) {
                throw new IllegalArgumentException("The user doesn't exist!");
            }
            Vector<Long> toDelete = new Vector<Long>();
            for (Friendship friendship : getFriendships()) {
                if (friendship.getIdUser2().equals(id) || friendship.getIdUser1().equals(id)) {
                    toDelete.add(friendship.getId());
                }
            }
            for(Long idToDelete : toDelete) {
                repositoryFriendship.delete(idToDelete);
            }
            User user = repositoryUser.delete(id);
            for (User friend : u.getFriends())
                friend.removeFriend(u);
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid user! ");
        }
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
        User user1 = repositoryUser.findOne(friendship.getIdUser1());
        User user2 = repositoryUser.findOne(friendship.getIdUser2());
        if (getFriendships() != null) {
            for (Friendship f : getFriendships()) {
                if (f.getIdUser1().equals(friendship.getIdUser1()) && f.getIdUser2().equals(friendship.getIdUser2())) {
                    throw new IllegalArgumentException("The friendship already exist! ");
                }
            }
            if (repositoryUser.findOne(friendship.getIdUser1()) == null || repositoryUser.findOne(friendship.getIdUser2()) == null) {
                throw new IllegalArgumentException("User doesn't exist! ");
            }
            if (friendship.getIdUser1().equals(friendship.getIdUser2()))
                throw new IllegalArgumentException("IDs can't be the same!!! ");
        }
        friendship.setId(getNewFriendshipId());
        repositoryFriendship.save(friendship);

        user1.addFriend(user2);
        user2.addFriend(user1);
    }


    public void removeFriendship(Long id1, Long id2) {
        User user1 = repositoryUser.findOne(id1);
        User user2 = repositoryUser.findOne(id2);

        Long id = 0L;
        for (Friendship f : repositoryFriendship.findAll()) {
            if ((f.getIdUser1().equals(id1) && f.getIdUser2().equals(id2)) || (f.getIdUser1().equals(id2) && f.getIdUser2().equals(id1)))
                id = f.getId();
        }
        if (id == 0L)
            throw new IllegalArgumentException("The friendship doesn't exist!");
        repositoryFriendship.delete(id);

//
//        if (user1 == null)
//            throw new IllegalArgumentException("The user doesn't exist!");
//
//        if (user2 == null)
//            throw new IllegalArgumentException("The user doesn't exist!");
//
//        if (user1.getId() == user2.getId()) {
//            throw new IllegalArgumentException("IDs can't be equal! ");
//        }
//
//        for (User friend : user2.getFriends()) {
//            if (!user1.equals(friend)) {
//                throw new IllegalArgumentException("Friendship doesn't exist!");
//            }
//        }

        user1.removeFriend(user2);
        user2.removeFriend(user1);

//        for (Friendship f : repositoryFriendship.findAll()) {
//            if ((f.getIdUser1().equals(id1) && f.getIdUser2().equals(id2)) || (f.getIdUser1().equals(id2) && f.getIdUser2().equals(id1))) {
//                repositoryFriendship.delete(f.getId());
//            }
//        }
    }
}
