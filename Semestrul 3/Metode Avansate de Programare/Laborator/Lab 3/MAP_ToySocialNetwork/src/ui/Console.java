package ui;

import domain.Friendship;
import domain.User;
import domain.validators.ValidationException;
import service.SocialCommunities;
import service.SocialNetwork;

import java.util.Scanner;

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
//                case "8":
//                    printMostSocialCommunity();
//                    break;
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

    void printUsers() {
        System.out.println("\t\t\tUSERS\t\t\t");
        for (User u : socialNetwork.getUsers()) {
            System.out.println("ID: " + u.getId() + " " + u.getFirstName() + " " + u.getLastName());
        }
    }

    void addUser() {
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

    void removeUser() {
        printUsers();
        Scanner scan = new Scanner(System.in);
        System.out.println("Id: ");
        String var = scan.nextLine();
        try {
            Long id = Long.parseLong(var);
            socialNetwork.removeUser(id);
        } catch (IllegalArgumentException e) {
            System.out.println("ID must be a number! It can't contain letters or symbols! ");
        }
    }

    void printFriendships() {

//        for (User u : socialNetwork.getUsers()) {
//            System.out.println("Friends of user: " + u.getFirstName() + " " + u.getLastName());
//            for (Friendship f : socialNetwork.getFriendships()) {
//                if (f.getIdUser1().equals(u.getId())) {
//                    System.out.println(socialNetwork.findUser(f.getIdUser2()).getFirstName());
//                } else if (f.getIdUser2().equals(u.getId())) {
//                    System.out.println(socialNetwork.findUser(f.getIdUser1()).getFirstName());
//                }
//            }
//        }

        for (User u : socialNetwork.getUsers()) {
            System.out.println("Friends of user: " + u.getFirstName() + " " + u.getLastName() + " ( " + u.getFriends().size() + " )");
            if (u.getFriends() != null) {
                for (User f : u.getFriends()) {
                    System.out.println("( ID" + f.getId() + " ) " + f.getFirstName() + " " + f.getLastName());
                }
            }
        }
    }

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

    private void printConnectedCommunities() {
        System.out.println("Social Communities");
        int nrOfCommunities = socialCommunities.connectedCommunities();
        System.out.println("Number of Social Communities: " + nrOfCommunities);
    }

//    private void printMostSocialCommunity() {
//        socialCommunities.mostSocialCommunity();
//    }

}
