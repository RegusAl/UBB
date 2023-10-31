

import domain.Friendship;
import domain.Tuple;
import domain.User;
import domain.validators.FriendshipValidator;
import domain.validators.UserValidator;
import domain.validators.ValidationException;
import repository.InMemoryRepository;
import service.SocialNetwork;
import ui.Console;

public class Main {

    public static void main(String[] args) {


        InMemoryRepository<Long, User> repoUser = new InMemoryRepository<>(new UserValidator());
        InMemoryRepository<Long, Friendship> repoFriendship = new InMemoryRepository<>(new FriendshipValidator(repoUser));

        SocialNetwork socialNetwork = new SocialNetwork(repoUser, repoFriendship);
        Console ui = new Console(socialNetwork);

        User u1 = new User("A", "A");
        User u2 = new User("B", "B");
        User u3 = new User("C", "C");
        User u4 = new User("D", "D");
        User u5 = new User("E", "E");
        User u6 = new User("F", "F");
        User u7 = new User("G", "G");
        User u8 = new User("H", "H");

        socialNetwork.addUser(u1);
        socialNetwork.addUser(u2);
        socialNetwork.addUser(u3);
        socialNetwork.addUser(u4);
        socialNetwork.addUser(u5);
        socialNetwork.addUser(u6);
        socialNetwork.addUser(u7);
        socialNetwork.addUser(u8);

        ui.run();
    }
}

