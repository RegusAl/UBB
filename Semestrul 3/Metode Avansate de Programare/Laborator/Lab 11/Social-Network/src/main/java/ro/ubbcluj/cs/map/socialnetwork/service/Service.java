package ro.ubbcluj.cs.map.socialnetwork.service;

import ro.ubbcluj.cs.map.socialnetwork.domain.FriendRequest;
import ro.ubbcluj.cs.map.socialnetwork.domain.Friendship;
import ro.ubbcluj.cs.map.socialnetwork.domain.Message;
import ro.ubbcluj.cs.map.socialnetwork.domain.User;
import ro.ubbcluj.cs.map.socialnetwork.repository.*;

import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;

public class Service implements ServiceI {
    protected final PagingRepository<Long, User> userRepo;
    protected final FriendRequestPagingRepository<Long, Friendship> friendshipRepo;
    protected final MessagePagingRepository<Long, Message> messageRepo;

    String yellowColorCode = "\u001B[33m";

    String resetColorCode = "\u001B[0m";


    public Service(PagingRepository<Long, User> userRepo, FriendRequestPagingRepository<Long, Friendship> friendshipRepo, MessagePagingRepository<Long, Message> messageRepo) {
        this.userRepo = userRepo;
        this.friendshipRepo = friendshipRepo;
        this.messageRepo = messageRepo;
    }

    public Repository<Long, Friendship> getFriendshipRepo() {
        return friendshipRepo;
    }

    @Override
    public boolean addUser(String firstName, String lastName, String email, String password) {
        try {
            if (password.isEmpty()) return false;
            if (getUserByEmail(email) != null)
                throw new Exception("The email already exist");

            User u = new User(firstName, lastName, email);
            u.setPassword(password);
            userRepo.save(u);
            return true;
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }

    @Override
    public boolean deleteUser(String email) {
        try {
            User u = getUserByEmail(email);
            if (u == null)
                throw new Exception("The email does not exist");

            // Delete all user's friendships
            for (Friendship f: friendList(u)) {
                friendshipRepo.delete(f.getId());
            }

            userRepo.delete(u.getId());
            return true;
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }

    @Override
    public boolean createFriendship(String email1, String email2) {
        try {
            if (getFriendshipByEmail(email1, email2) != null)
                throw new Exception("The friendship already exist");

            User u1 = getUserByEmail(email1);
            User u2 = getUserByEmail(email2);

            Friendship f = new Friendship(u1.getId(), u2.getId(), FriendRequest.ACCEPTED);
            friendshipRepo.save(f);
            return true;
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }

    @Override
    public boolean createFriendRequest(String email1, String email2) {
        try {
            Friendship friendship = getFriendshipByEmail(email1, email2);
            if (friendship != null && friendship.getFriendRequestStatus() != FriendRequest.REJECTED)
                throw new Exception("The friend request exists and it is not rejected");
            else if (friendship != null && friendship.getFriendRequestStatus() == FriendRequest.REJECTED) {
                friendship.setFriendRequestStatus(FriendRequest.PENDING);
                friendshipRepo.update(friendship);
                return true;
            } else {
                User u1 = getUserByEmail(email1);
                User u2 = getUserByEmail(email2);

                Friendship f = new Friendship(u1, u2);
                friendshipRepo.save(f);
                return true;
            }
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }

    @Override
    public boolean respondFriendRequest(Friendship friendshipReq, FriendRequest response) {
        try {
            if (!friendshipRepo.findOne(friendshipReq.getId()).isPresent())
                throw new Exception("The friend request does not exist");
            else if (friendshipReq.getFriendRequestStatus() != FriendRequest.PENDING)
                throw new Exception("The friend request is not pending");

            friendshipReq.setFriendRequestStatus(response);
            friendshipRepo.update(friendshipReq);
            return true;
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }


    @Override
    public boolean deleteFriendship(String email1, String email2) {
        try {
            Friendship f = getFriendshipByEmail(email1, email2);
            if (f == null)
                throw new Exception("Friendship not found");

            friendshipRepo.delete(f.getId());
            return true;
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }

    @Override
    public Iterable<User> getAllUsers() {
        return userRepo.findAll();
    }

    @Override
    public Page<User> findAllUsers(Pageable pageable) {
        return userRepo.findAll(pageable);
    }

    @Override
    public Page<Friendship> findAllFriendships(Pageable pageable) {
        return friendshipRepo.findAll(pageable);
    }

    @Override
    public Page<Friendship> findAllUserFriends(Pageable pageable, User user) {
        Page<Friendship> pgF = friendshipRepo.findAllUserFriends(pageable, user.getId());
        for (Friendship f: pgF.getElementsOnPage()) {
            f.setNameUser1(userRepo.findOne(f.getUser1Id()).get().getFirstName() + " " +
                    userRepo.findOne(f.getUser1Id()).get().getLastName());
            f.setNameUser2(userRepo.findOne(f.getUser2Id()).get().getFirstName() + " " +
                    userRepo.findOne(f.getUser2Id()).get().getLastName());
        }
        return pgF;
    }

    @Override
    public Page<Friendship> findAllFriendRequests(Pageable pageable) {
        return friendshipRepo.findAllFriendRequests(pageable);
    }

    @Override
    public Page<Friendship> findAllUserFriendRequests(Pageable pageable, User user) {
       Page<Friendship> pgF = friendshipRepo.findAllUserFriendRequests(pageable, user.getId());
       for (Friendship f: pgF.getElementsOnPage()) {
           f.setNameUser1(userRepo.findOne(f.getUser1Id()).get().getFirstName() + " " +
                   userRepo.findOne(f.getUser1Id()).get().getLastName());
           f.setNameUser2(userRepo.findOne(f.getUser2Id()).get().getFirstName() + " " +
                   userRepo.findOne(f.getUser2Id()).get().getLastName());
       }
       return pgF;
    }

    @Override
    public Page<Message> findAllMessages(Pageable pageable, String emailFrom, String emailTo) {

        User u1 = getUserByEmail(emailFrom);
        User u2 = getUserByEmail(emailTo);

        if (u1 != null && u2 != null) {
            Long user1Id = u1.getId();
            Long user2Id = u2.getId();
            return messageRepo.findAll(pageable, user1Id, user2Id);
        } else {
            return new Page<>(null, 0);
        }
    }

    @Override
    public Iterable<Friendship> getAllFriendships() {
        return friendshipRepo.findAll();
    }

    @Override
    public Iterable<Message> getAllMessages() {
        return messageRepo.findAll();
    }

    /**
     * dfs algorithm - get the component that includes a given vertex
     * @param user the vertex where we start
     * @param visited set of vertexes already visited
     * @param adjacencyList the adjacency list
     * @param currentComponent - a list where we put the visited vertexes
     */
    private static void dfs(User user, Set<User> visited, Map<User, List<User>> adjacencyList,
                            List<User> currentComponent) {
        visited.add(user);
        currentComponent.add(user);

        for (User friend : adjacencyList.getOrDefault(user, Collections.emptyList())) {
            if (!visited.contains(friend)) {
                dfs(friend, visited, adjacencyList, currentComponent);
            }
        }
    }
    @Override
    public int numberOfCommunities() {
        List<List<User>> communities = getAllCommunities();
        return communities.size();
    }

    @Override
    public List<List<User>> mostSociableCommunity() {
        List<List<User>> communities = getAllCommunities();
        List<List<User>> biggestComponents = new ArrayList<>();
        int maxComponentSize = 0;

        for (List<User> currentComponent : communities) {
            int currentComponentSize = currentComponent.size();
            if (currentComponentSize > maxComponentSize) {
                biggestComponents.clear();
                biggestComponents.add(currentComponent);
                maxComponentSize = currentComponentSize;
            } else if (currentComponentSize == maxComponentSize) {
                biggestComponents.add(currentComponent);
            }
        }

        return biggestComponents;
    }

    @Override
    public List<List<User>> getAllCommunities() {
        Map<User, List<User>> adjacencyList = new HashMap<>();

        // Populate adjacency list based on friendships
        for (Friendship friendship : getAllFriendships()) {
            User u1 = userRepo.findOne(friendship.getUser1Id()).get();
            User u2 = userRepo.findOne(friendship.getUser2Id()).get();
            adjacencyList.computeIfAbsent(u1, k -> new ArrayList<>()).add(u2);
            adjacencyList.computeIfAbsent(u2, k -> new ArrayList<>()).add(u1);
        }

        Set<User> visited = new HashSet<>();
        List<List<User>> components = new ArrayList<>();

        for (User user : getAllUsers()) {
            if (!visited.contains(user)) {
                List<User> currentComponent = new ArrayList<>();
                dfs(user, visited, adjacencyList, currentComponent);
                components.add(currentComponent);
            }
        }

        return components;
    }

    @Override
    public User getUserByEmail(String email) {
        Iterable<User> lst = userRepo.findAll();
        for (User u : lst) {
            if (u.getEmail().equals(email))
                return u;
        }
        return null;
    }

    @Override
    public Friendship getFriendshipByEmail(String email1, String email2) {
        Iterable<Friendship> lst = friendshipRepo.findAll();
        User u1 = getUserByEmail(email1);
        User u2 = getUserByEmail(email2);

        if (u1 == null || u2 == null)
            return null;

        for (Friendship fr : lst) {
            if (fr.equals(new Friendship(u1, u2))) {
                return fr;
            }
        }
        return null;
    }


    @Override
    public ArrayList<Friendship> friendList(User user) {
        Collection<Friendship> friendships = (Collection<Friendship>) friendshipRepo.findAll();
        return friendships.stream()
                .filter(x -> (x.getUser1Id().equals(user.getId()) || x.getUser2Id().equals(user.getId())) &&
                        x.getFriendRequestStatus() == FriendRequest.ACCEPTED)
                .collect(Collectors.toCollection(ArrayList::new));

    }

    @Override
    public ArrayList<Friendship> friendRequestList(User user) {
        Collection<Friendship> friendships = (Collection<Friendship>) friendshipRepo.findAll();
        return friendships.stream()
                .filter(x -> (x.getUser1Id().equals(user.getId()) || x.getUser2Id().equals(user.getId())))
                .collect(Collectors.toCollection(ArrayList::new));

    }

    @Override
    public Map<LocalDateTime, User> friendListFrom(User user, Integer month) {
        ArrayList<Friendship> friendList = friendList(user);

        return friendList.stream()
                .filter(f -> f.getFriendsFrom().getMonthValue() == month)
                .collect(Collectors.toMap(Friendship::getFriendsFrom, f -> {
                    if (f.getUser1Id().equals(user.getId())) {
                        return userRepo.findOne(f.getUser2Id()).orElseThrow(() -> new RuntimeException("User not found"));
                    } else {
                        return userRepo.findOne(f.getUser1Id()).orElseThrow(() -> new RuntimeException("User not found"));
                    }
                }));
    }

    @Override
    public User findUser(String id) {
        try {
            Long ID = Long.parseLong(id);
            Optional<User> u = userRepo.findOne(ID);
            if (!u.isPresent()) {
                throw new Exception("ID not found");
            }
            return u.get();
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
        }
        return null;
    }

    @Override
    public boolean updateUser(String id, String firstName, String lastName, String email) {
        try {
            Long ID = Long.parseLong(id);
            if (!userRepo.findOne(ID).isPresent()) {
                throw new Exception("ID not found");
            }
            User u = new User(firstName, lastName, email);
            u.setId(ID);

            userRepo.update(u);
            return true;
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }

    @Override
    public boolean addMessage(String email_from, List<String> emails_to, String message) {
        try {
            User from = getUserByEmail(email_from);
            List<User> toUsers = new ArrayList<>();
            for (String email : emails_to) {
                User u = getUserByEmail(email);
                if(u != null) {
                    toUsers.add(u);
                } else {
                    throw new Exception("Email does not exist");
                }
            }

            if (from == null || toUsers.isEmpty())
                throw new Exception("Email does not exist");
            if (Objects.equals(message, ""))
                throw new Exception("Message is empty");

            Message msg = new Message(from, toUsers, message);
            messageRepo.save(msg);

            return true;
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }

    @Override
    public boolean addMessage(String email_from, List<String> emails_to, String message, Message replyTo) {
        try {
            User from = getUserByEmail(email_from);
            List<User> toUsers = new ArrayList<>();
            for (String email : emails_to) {
                User u = getUserByEmail(email);
                if(u != null) {
                    toUsers.add(u);
                } else {
                    throw new Exception("Email does not exist");
                }
            }

            if (from == null || toUsers.isEmpty())
                throw new Exception("Email does not exist");
            if (Objects.equals(message, ""))
                throw new Exception("Message is empty");

            Message msg = new Message(from, toUsers, message, replyTo);
            messageRepo.save(msg);

            return true;
        } catch (Exception e) {
            System.out.println(yellowColorCode + e.getMessage() + resetColorCode);
            return false;
        }
    }

    @Override
    public ArrayList<Message> getMessagesBetweenTwoUsers(String email1, String email2) {
        if (getUserByEmail(email1) == null || getUserByEmail(email2) == null)
            return new ArrayList<>();

        Collection<Message> messages = (Collection<Message>) messageRepo.findAll();
        return messages.stream()
                .filter(x -> (x.getFrom().getEmail().equals(email1) && userFoundByEmail(x.getTo(), email2)) ||
                        (x.getFrom().getEmail().equals(email2) && userFoundByEmail(x.getTo(), email1)))
                .sorted(Comparator.comparing(Message::getDate))
                .collect(Collectors.toCollection(ArrayList::new));

    }

    @Override
    public boolean updateMessage(Message msg) {
        messageRepo.update(msg);
        return true;
    }

    boolean userFoundByEmail(List<User> users, String email) {
        for (User u: users) {
            if (u.getEmail().equals(email))
                return true;
        }

        return false;
    }
}
