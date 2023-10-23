

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

        SocialNetwork socialNetwork = new SocialNetwork(repoUser);
        Console ui = new Console(socialNetwork);

        User u1 = new User("A", "A");
        User u2 = new User("B", "B");
        User u3 = new User("C", "C");
        User u4 = new User("D", "D");

        socialNetwork.addUser(u1);
        socialNetwork.addUser(u2);
        socialNetwork.addUser(u3);
        socialNetwork.addUser(u4);

        ui.run();
    }
}

