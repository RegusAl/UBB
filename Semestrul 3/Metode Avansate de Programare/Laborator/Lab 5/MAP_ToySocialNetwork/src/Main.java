

import domain.Friendship;
import domain.validators.FriendshipValidator;
import domain.validators.UserValidator;
import repository.FriendshipFileRepository;
import repository.InMemoryRepository;
import repository.UserFileRepository;
import service.SocialNetwork;
import ui.Console;

public class Main {

    public static void main(String[] args) {


//        InMemoryRepository<Long, User> repoUser = new InMemoryRepository<>(new UserValidator());
//        InMemoryRepository<Long, Friendship> repoFriendship = new InMemoryRepository<>(new FriendshipValidator(repoUser));

        UserFileRepository repoUser = new UserFileRepository("data/Users.csv", new UserValidator());
        FriendshipFileRepository repoFriendship = new FriendshipFileRepository("data/Friendships.csv", new FriendshipValidator(repoUser));

        SocialNetwork socialNetwork = new SocialNetwork(repoUser, repoFriendship);
        Console ui = new Console(socialNetwork);


        ui.run();
    }
}

