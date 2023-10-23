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

    public SocialNetwork(InMemoryRepository<Long, User> repositoryUser) {
        this.repositoryUser = repositoryUser;
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
        for (User friend : u.getFriends())
            friend.removeFriend(u);
//        for(Friendship f : repositoryFriendship.findAll()) {
//            if(f.getIdUser1().equals(id) || f.getIdUser2().equals(id)) {
//                repositoryFriendship.delete(f.getId());
//            }
//        }
        repositoryUser.delete(id);
    }

//    public Iterable<Friendship> getFriendships() {
//        return repositoryFriendship.findAll();
//    }

//    public Long getNewFriendshipId() {
//        Long id = 0L;
//        for (Friendship f : repositoryFriendship.findAll()) {
//            id = f.getId();
//        }
//        id++;
//        return id;
//    }

    public void addFriendship(Friendship friendship) {
        User user1 = repositoryUser.findOne(friendship.getIdUser1());
        User user2 = repositoryUser.findOne(friendship.getIdUser2());

        if(user1 == null)
            throw new IllegalArgumentException("The user doesn't exist!");

        if(user2 == null)
            throw new IllegalArgumentException("The user doesn't exist!");

        if(user1.getId()==user2.getId()) {
            throw new IllegalArgumentException("IDs can't be equal! ");
        }

        for (User friend : user2.getFriends()) {
            if (user1.equals(friend)) {
                throw new IllegalArgumentException("Friendship already exist! ");
            }
        }

        user1.addFriend(user2);
        user2.addFriend(user1);

//        friendship.setId(getNewFriendshipId());
//        repositoryFriendship.save(friendship);
    }


    public void removeFriendship(Long id1, Long id2) {
        User user1 = repositoryUser.findOne(id1);
        User user2 = repositoryUser.findOne(id2);


        if(user1 == null)
            throw new IllegalArgumentException("The user doesn't exist!");

        if(user2 == null)
            throw new IllegalArgumentException("The user doesn't exist!");

        if(user1.getId()==user2.getId()) {
            throw new IllegalArgumentException("IDs can't be equal! ");
        }

        for (User friend : user2.getFriends()) {
            if (!user1.equals(friend)) {
                throw new IllegalArgumentException("Friendship doesn't exist!");
            }
        }

        user1.removeFriend(user2);
        user2.removeFriend(user1);

//        for (Friendship f : repositoryFriendship.findAll()) {
//            if ((f.getIdUser1().equals(id1) && f.getIdUser2().equals(id2)) || (f.getIdUser1().equals(id2) && f.getIdUser2().equals(id1))) {
//                repositoryFriendship.delete(f.getId());
//            }
//        }
    }
}
