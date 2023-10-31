package ui;

import domain.Friendship;
import domain.User;
import domain.validators.ValidationException;
import service.SocialCommunities;
import service.SocialNetwork;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Scanner;
import java.util.function.Predicate;

public class Console {

    private SocialNetwork socialNetwork;
    private SocialCommunities socialCommunities;

    public Console(SocialNetwork socialNetwork) {
        this.socialNetwork = socialNetwork;
        this.socialCommunities = new SocialCommunities(socialNetwork);
    }

    void printMenu() {
        System.out.println("\t\t\tMENU\t\t\t");
        System.out.println("1. Add user");
        System.out.println("2. Remove user");
        System.out.println("3. Add friendship");
        System.out.println("4. Remove friendship");
        System.out.println("5. Print users");
        System.out.println("6. Print friendships");
        System.out.println("7. Communities");
        System.out.println("8. Most social community");
        System.out.println("9. List of users with at least N friends");
        System.out.println("0. EXIT");
    }

    public void run() {
        Scanner scan = new Scanner(System.in);
        boolean ok = true;
        while (ok) {
            printMenu();
            String input = scan.nextLine();
            switch (input) {
                case "1":
                    addUser();
                    break;
                case "2":
                    removeUser();
                    break;
                case "3":
                    addFriendship();
                    break;
                case "4":
                    removeFriendship();
                    break;
                case "5":
                    printUsers();
                    break;
                case "6":
                    printFriendships();
                    break;
                case "7":
                    printConnectedCommunities();
                    break;
                case "8":
                    printMostSocialCommunity();
                    break;
                case "9":
                    printListOfUsersWithNFriends();
                    break;
                case "0":
                    System.out.println("exit");
                    ok = false;
                    break;
                default:
                    System.out.println("Invalid input!");
                    break;
            }
        }
    }

    private void printListOfUsersWithNFriends() {
        System.out.println("N: ");
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        Predicate<User> hasAtLeastNFriends = u -> u.getFriends().size() < N;
        List<User> users = new ArrayList<>((Collection) socialNetwork.getUsers());
        users.removeIf(hasAtLeastNFriends);
        users.forEach(u -> System.out.println(u.getFirstName() + " " + u.getLastName() + " " + u.getFriends().size() + " friend/s"));
//        users.stream()
//                .filter(u -> u.getFriends().size() >= N)
//                .forEach(u -> System.out.println(u.getFirstName() + " " + u.getLastName() + " " + u.getFriends().size() + " friend/s"));
//
    }


    /**
     * Prints the users from the social network
     */
    void printUsers() {
        System.out.println("\t\t\tUSERS\t\t\t");
        socialNetwork.getUsers().forEach(u -> {
            System.out.println("ID: " + u.getId() + " " + u.getFirstName() + " " + u.getLastName());
        });
    }


    /**
     * Adds user to the social network
     */
    void addUser() {
        System.out.println("Add user");
        Scanner scan = new Scanner(System.in);
        System.out.println("First name: ");
        String firstName = scan.nextLine();
        System.out.println("Last name: ");
        String lastName = scan.nextLine();
        try {
            socialNetwork.addUser(new User(firstName, lastName));
        } catch (ValidationException e) {
            System.out.println("Invalid user!");
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid argument");
        }

    }


    /**
     * Removes user from social network
     */
    void removeUser() {
        printUsers();
        System.out.println("Remove user");
        Scanner scan = new Scanner(System.in);
        System.out.println("Id: ");
        String var = scan.nextLine();
        try {
            Long id = Long.parseLong(var);
            User user = socialNetwork.removeUser(id);
            if (user == null) throw new ValidationException("User doesn,t exist!");
            System.out.println("User: " + user.getId() + " " + user.getFirstName() + " " + user.getLastName() + " was removed.");
        } catch (IllegalArgumentException e) {
            System.out.println("ID must be a number! It can't contain letters or symbols! ");
        } catch (ValidationException v) {
            System.out.println("User doesn't exist!");
        }
    }


    /**
     * Prints friendships
     */
    void printFriendships() {
        for (User u : socialNetwork.getUsers()) {
            System.out.println("Friends of user: " + u.getFirstName() + " " + u.getLastName() + " ( Number of friends: " + u.getFriends().size() + " )");
            if (u.getFriends() != null) {
//                for (User f : u.getFriends()) {
//                    System.out.println("( ID: " + f.getId() + " ) " + f.getFirstName() + " " + f.getLastName());
//                }
                u.getFriends().forEach(f -> {
                    System.out.println("( ID: " + f.getId() + " ) " + f.getFirstName() + " " + f.getLastName());
                });
            }
        }
    }

    /**
     * Adds a new friendship between two users
     */
    void addFriendship() {
        Scanner scan = new Scanner(System.in);
        System.out.println("ID of the first user: ");
        String var1 = scan.nextLine();
        System.out.println("ID of the second user: ");
        String var2 = scan.nextLine();
        try {
            Long id1 = 0L, id2 = 0L;
            try {
                id1 = Long.parseLong(var1);
                id2 = Long.parseLong(var2);
            } catch (IllegalArgumentException e) {
                System.out.println("ID must be a number! It can't contain letters or symbols! ");
            }
            socialNetwork.addFriendship(new Friendship(id1, id2));
        } catch (ValidationException e) {
            System.out.println("Friendship is invalid! ");
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid arguments! ");
        }
    }


    /**
     * Removes a friendship between two friends
     */
    private void removeFriendship() {
        Scanner scan = new Scanner(System.in);
        System.out.println("ID of the first user: ");
        String var1 = scan.nextLine();
        System.out.println("ID of the second user: ");
        String var2 = scan.nextLine();
        try {
            Long id1 = 0L, id2 = 0L;
            try {
                id1 = Long.parseLong(var1);
                id2 = Long.parseLong(var2);
            } catch (IllegalArgumentException e) {
                System.out.println("ID must be a number! It can't contain letters or symbols! ");
            }
            socialNetwork.removeFriendship(id1, id2);
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid arguments! ");
        }
    }


    /**
     * Prints connected communities
     */
    private void printConnectedCommunities() {
        System.out.println("Social Communities\n");
        int nrOfCommunities = socialCommunities.connectedCommunities();
        System.out.println("Number of Social Communities: " + nrOfCommunities);
    }

    private void printMostSocialCommunity() {
        System.out.println("Most social community: ");
        List<Long> mostSocialCommunity = socialCommunities.mostSocialCommunity();
        mostSocialCommunity.forEach(System.out::println);
    }

}
