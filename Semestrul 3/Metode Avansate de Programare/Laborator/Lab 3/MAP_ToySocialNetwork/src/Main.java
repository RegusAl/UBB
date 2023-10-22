

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

//        User u1 = new User("u1FirstName", "u1LastName");
//        u1.setId(1l);
//        User u2 = new User("u2FirstName", "u2LastName");
//        u2.setId(1l);
//        User u3 = new User("u3FirstName", "u3LastName");
//        u3.setId(1l);
//        User u4 = new User("u4FirstName", "u4LastName");
//        u4.setId(1l);
//        User u5 = new User("u5FirstName", "u5LastName");
//        u5.setId(1l);
//        User u6 = new User("u6FirstName", "u6LastName");
//        u6.setId(1l);
//        User u7 = new User("u7FirstName", "u7LastName");
//        u7.setId(1l);
//
        InMemoryRepository<Long, User> repoUser = new InMemoryRepository<>(new UserValidator());
        InMemoryRepository<Long, Friendship> repoFriendship = new InMemoryRepository<>(new FriendshipValidator());


//        repo.save(u1);
//        repo.save(u2);
//        repo.save(u3);
//        repo.save(u4);
//        repo.save(u5);
//        repo.save(u6);
//        repo.save(u7);

        SocialNetwork socialNetwork = new SocialNetwork(repoUser, repoFriendship);
        Console ui = new Console(socialNetwork);
        ui.run();
    }
}

