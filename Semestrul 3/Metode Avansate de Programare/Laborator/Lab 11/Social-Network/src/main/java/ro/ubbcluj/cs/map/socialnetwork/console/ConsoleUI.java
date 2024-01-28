package ro.ubbcluj.cs.map.socialnetwork.console;



import ro.ubbcluj.cs.map.socialnetwork.domain.Friendship;
import ro.ubbcluj.cs.map.socialnetwork.domain.User;
import ro.ubbcluj.cs.map.socialnetwork.service.ServiceI;

import java.util.List;
import java.util.Scanner;

public class ConsoleUI extends AbstractUI {

    private Scanner scanner;

    public ConsoleUI(ServiceI srv) {
        super(srv);
        this.scanner = new Scanner(System.in);
    }

    @Override
    public void run() {
        printMenu();

        User user;
        String firstName, lastName, email, password;
        String email1, email2;
        Iterable<User> userList;
        Iterable<Friendship> friendshipList;
        List<List<User>> communityList;
        Integer month;
        while (true) {
            System.out.println("Press m to see the menu\nCommand: ");
            String command = scanner.next();

            switch (command) {
                case "1":
                    // Add a user
                    firstName = readFirstName();
                    lastName = readLastName();
                    email = readEmail();
                    password = readPassword();
                    if (srv.addUser(firstName, lastName, email, password))
                        System.out.println("Done!");
                    break;
                case "2":
                    // Delete a user
                    email = readEmail();
                    if (srv.deleteUser(email))
                        System.out.println("Done!");
                    break;
                case "3":
                    // Create a friendship
                    email1 = readEmail();
                    email2 = readEmail();
                    if(srv.createFriendship(email1, email2))
                        System.out.println("Done!");
                    break;
                case "4":
                    // Delete a friendship
                    email1 = readEmail();
                    email2 = readEmail();
                    if (srv.deleteFriendship(email1, email2))
                        System.out.println("Done!");
                    break;
                case "5":
                    // Number of communities
                    System.out.println("Numbers of communities: " + srv.numberOfCommunities());
                    break;
                case "6":
                    // The most sociable community
                    communityList = srv.mostSociableCommunity();
                    for (List<User> community : communityList) {
                        System.out.println("Community: ");
                        community.forEach(System.out::println);
                        System.out.println();
                    }
                    break;
                case "pU":
                    // Print all users
                    userList = srv.getAllUsers();
                    userList.forEach(System.out::println);
                    break;
                case "pF":
                    // Print all friendships
                    friendshipList = srv.getAllFriendships();
                    friendshipList.forEach(System.out::println);
                    break;
                case "pC":
                    // Print friendship components
                    communityList = srv.getAllCommunities();
                    communityList.forEach(System.out::println);
                    break;
                case "p":
                    // Print all friends of a user from a specific month of the year
                    email = readEmail();
                    user = srv.getUserByEmail(email);
                    month = readMonth();
                    if (month >0 && month < 13) {
                        srv.friendListFrom(user, month).forEach((date, friend) ->
                                System.out.println("Surname: " + friend.getLastName() + "| Forename: " + friend.getFirstName()
                                        + "| Date: " + date));
                    } else System.out.println("\u001B[33m" + "There is no such month" + "\u001B[0m");

                    break;
                case "m":
                    printMenu();
                    break;
                case "x":
                    return;
                case ":((":
                   // srv.addMessage("ana@user.com", Arrays.asList("nicu@user.com", "mara@user.com"), "Te rog sa mergi");
//                    srv.addMessage("nicu@user.com", "ana@user.com", "Te rog sa mergi");
//                    Iterable<Message> lst = srv.getAllMessages();
                    srv.getAllMessages().forEach(System.out::println);
                    break;
                default:
                    break;
            }
        }
    }

    public void printMenu() {
        System.out.println("******************************");
        System.out.println("1 - add user");
        System.out.println("2 - delete user");
        System.out.println("3 - add friendship");
        System.out.println("4 - remove friendship");
        System.out.println("5 - number of communities");
        System.out.println("6 - most sociable community");
        System.out.println("pU - print all users");
        System.out.println("pF - print all friendships");
        System.out.println("x - exit");
        System.out.println("******************************");
    }

    public String readFirstName() {
        System.out.print("First name: ");
        return scanner.next();
    }

    public String readLastName() {
        System.out.print("Last name: ");
        return scanner.next();
    }

    public String readEmail() {
        System.out.print("Email: ");
        return scanner.next();
    }

    public Integer readMonth() {
        System.out.print("Month - number: ");
        return scanner.nextInt();
    }

    public String readPassword() {
        System.out.print("Password: ");
        return scanner.next();
    }
}
