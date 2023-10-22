package service;

import domain.Entity;
import domain.Friendship;
import domain.Tuple;
import domain.User;
import domain.validators.UserValidator;
import repository.InMemoryRepository;
import repository.Repository;

import java.util.Random;
import java.util.UUID;

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

    public void removeUser(Long id) {
        User u = repositoryUser.findOne(id);
        if (u == null) {
            throw new IllegalArgumentException("The user doesn't exist!");
        }
        repositoryUser.delete(id);
    }

    public Iterable<Friendship> getFriendships() {
        return repositoryFriendship.findAll();
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

        user1.addFriend(user2);
        user2.addFriend(user1);

        friendship.setId(getNewFriendshipId());
        repositoryFriendship.save(friendship);
    }
}
