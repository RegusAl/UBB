package map.toysocialnetwork.service;

import map.toysocialnetwork.domain.Friendship;
import map.toysocialnetwork.domain.User;
import map.toysocialnetwork.domain.validators.ValidationException;
import map.toysocialnetwork.repository.database.FriendshipDBRepository;
import map.toysocialnetwork.repository.database.UserDBRepository;
import map.toysocialnetwork.utils.Observable;
import map.toysocialnetwork.utils.Observer;
import map.toysocialnetwork.utils.events.ChangeEventType;
import map.toysocialnetwork.utils.events.UserEvent;


import java.util.*;

public class SocialNetwork implements Observable<UserEvent> {

    private final UserDBRepository repositoryUser;
    private final FriendshipDBRepository repositoryFriendship;

    private final List<Observer<UserEvent>> observers;

    public SocialNetwork(UserDBRepository repositoryUser, FriendshipDBRepository repositoryFriendship) {
        this.repositoryUser = repositoryUser;
        this.repositoryFriendship = repositoryFriendship;
        this.observers = new ArrayList<>();
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
//    public Long getNewUserId() {
//        Long id = 0L;
//        for (User u : repositoryUser.findAll()) {
//            id = u.getId();
//        }
//        id++;
//        return id;
//    }

    /**
     * @param user Adds the user to the map.repository
     */
    public User addUser(User user) {
//        user.setId(getNewUserId());
        Optional<User> newUser = repositoryUser.save(user);
        notifyObservers(new UserEvent(ChangeEventType.ADD, user));
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
//            Vector<Long> toDelete = new Vector<>();
//            getFriendships().forEach(friendship -> {
//                if (friendship.getIdUser2().equals(id) || friendship.getIdUser1().equals(id)) {
//                    toDelete.add(friendship.getId());
//                }
//            });
//            toDelete.forEach(repositoryFriendship::delete);
            repositoryUser.delete(id);
            //            u.getFriends().forEach(friend -> friend.removeFriend(u));
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid user! ");
        } catch (ValidationException v) {
            System.out.println();
        }
        if(u!=null)
            notifyObservers(new UserEvent(ChangeEventType.DELETE, u));
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

    @Override
    public void addObserver(Observer<UserEvent> e) {
        observers.add(e);
    }

    @Override
    public void removeObserver(Observer<UserEvent> e) {
        observers.remove(e);
    }

    @Override
    public void notifyObservers(UserEvent t) {
        observers.forEach(x -> x.update(t));
    }
}
