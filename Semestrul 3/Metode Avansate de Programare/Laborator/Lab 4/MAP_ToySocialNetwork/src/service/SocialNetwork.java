package service;

import domain.Entity;
import domain.Friendship;
import domain.Tuple;
import domain.User;
import domain.validators.UserValidator;
import domain.validators.ValidationException;
import repository.InMemoryRepository;
import repository.Repository;

import java.util.List;
import java.util.Random;
import java.util.UUID;
import java.util.Vector;

public class SocialNetwork {

    private final InMemoryRepository<Long, User> repositoryUser;
    private final InMemoryRepository<Long, Friendship> repositoryFriendship;

    public SocialNetwork(InMemoryRepository<Long, User> repositoryUser, InMemoryRepository<Long, Friendship> repositoryFriendship) {
        this.repositoryUser = repositoryUser;
        this.repositoryFriendship = repositoryFriendship;
    }

    public Iterable<User> getUsers() {
        return repositoryUser.findAll();
    }

    public User findUser(Long id) {
        return repositoryUser.findOne(id).orElseThrow(() -> new ValidationException("No user"));
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

    public User removeUser(Long id) {
        try {
            User u = repositoryUser.findOne(id).orElseThrow(() -> new ValidationException("User doesn't exist!"));
            Vector<Long> toDelete = new Vector<>();
            for (Friendship friendship : getFriendships()) {
                if (friendship.getIdUser2().equals(id) || friendship.getIdUser1().equals(id)) {
                    toDelete.add(friendship.getId());
                }
            }
            for (Long idToDelete : toDelete) {
                repositoryFriendship.delete(idToDelete);
            }
            User user = repositoryUser.delete(id).orElseThrow();
            for (User friend : u.getFriends())
                friend.removeFriend(u);
            return user;
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid user! ");
        } catch (ValidationException v) {
            System.out.println();
        }
        return null;
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
        User user1 = null;
        User user2 = null;
        try {
            user1 = repositoryUser.findOne(friendship.getIdUser1()).orElseThrow(ValidationException::new);
            user2 = repositoryUser.findOne(friendship.getIdUser2()).orElseThrow(ValidationException::new);
        } catch (ValidationException v) {
            System.out.println();
        }
        if (getFriendships() != null) {
            for (Friendship f : getFriendships()) {
                if (f.getIdUser1().equals(friendship.getIdUser1()) && f.getIdUser2().equals(friendship.getIdUser2())) {
                    throw new ValidationException("The friendship already exist! ");
                }
            }
            if (repositoryUser.findOne(friendship.getIdUser1()).isEmpty() || repositoryUser.findOne(friendship.getIdUser2()).isEmpty()) {
                throw new ValidationException("User doesn't exist! ");
            }
            if (friendship.getIdUser1().equals(friendship.getIdUser2()))
                throw new ValidationException("IDs can't be the same!!! ");
        }
        friendship.setId(getNewFriendshipId());
        repositoryFriendship.save(friendship);

        assert user1 != null;
        user1.addFriend(user2);
        assert user2 != null;
        user2.addFriend(user1);
    }

    public void removeFriendship(Long id1, Long id2) {
        User user1 = null;
        User user2 = null;
        try {
            user1 = repositoryUser.findOne(id1).orElseThrow(() -> new ValidationException("User with id " + id1 + " doesn't exist!"));
            user2 = repositoryUser.findOne(id2).orElseThrow(() -> new ValidationException("User with id " + id2 + " doesn't exist!"));
        } catch (ValidationException v) {
            System.out.println();
        }
        Long id = 0L;
        for (Friendship f : repositoryFriendship.findAll()) {
            if ((f.getIdUser1().equals(id1) && f.getIdUser2().equals(id2)) || (f.getIdUser1().equals(id2) && f.getIdUser2().equals(id1)))
                id = f.getId();
        }
        if (id == 0L)
            throw new IllegalArgumentException("The friendship doesn't exist!");
        repositoryFriendship.delete(id);

        assert user1 != null;
        user1.removeFriend(user2);
        assert user2 != null;
        user2.removeFriend(user1);
    }
}