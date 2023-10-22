package ui;

import domain.Friendship;
import domain.User;
import service.SocialNetwork;

import java.util.Scanner;

public class Console {

    private SocialNetwork socialNetwork;

    public Console(SocialNetwork socialNetwork) {
        this.socialNetwork = socialNetwork;
    }

    void printMenu() {
        System.out.println("\t\t\tMENU\t\t\t");
        System.out.println("1. Add user");
        System.out.println("2. Remove user");
        System.out.println("3. Add friendship");
        System.out.println("4. Remove friendship");
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
                case "4":
                    break;
                case "5":
                    printUsers();
                    break;
                case "6":
                    printFriendships();
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

    void printUsers() {
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
        socialNetwork.addUser(new User(firstName, lastName));
    }

    void removeUser() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Id: ");
        Long id = Long.parseLong(scan.nextLine());
        socialNetwork.removeUser(id);

    }

    void printFriendships() {

        for (User u : socialNetwork.getUsers()) {
            System.out.println("Friends of user: " + u.getFirstName() + " " + u.getLastName());
            for (Friendship f : socialNetwork.getFriendships()) {
                if (f.getIdUser1().equals(u.getId())) {
                    System.out.println(socialNetwork.findUser(f.getIdUser2()).getFirstName());
                } else if (f.getIdUser2().equals(u.getId())) {
                    System.out.println(socialNetwork.findUser(f.getIdUser1()).getFirstName());
                }
            }
        }
//        for (User u : socialNetwork.getUsers()) {
////            System.out.println(u.getFirstName() + u.getLastName() + " is friends with: " + u.getFriends());
//            System.out.println(u.getFirstName());
//            if (u.getFriends() != null) {
//                for (User f : u.getFriends()) {
//                    System.out.println(f.getFirstName());
//                }
//            }
//        }
    }

    void addFriendship() {
        Scanner scan = new Scanner(System.in);
        System.out.println("ID of the first user: ");
        Long id1 = Long.parseLong(scan.nextLine());
        System.out.println("ID of the second user: ");
        Long id2 = Long.parseLong(scan.nextLine());
        socialNetwork.addFriendship(new Friendship(id1, id2));
    }


}
