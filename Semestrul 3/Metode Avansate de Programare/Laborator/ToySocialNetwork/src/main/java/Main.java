

import domain.Friendship;
import domain.User;
import domain.validators.FriendshipValidator;
import domain.validators.UserValidator;
import repository.FriendshipFileRepository;
import repository.InMemoryRepository;
import repository.Repository;
import repository.UserFileRepository;
import repository.database.UserDBRepository;
import service.SocialNetwork;
import ui.Console;

public class Main {

    public static void main(String[] args) {


//        InMemoryRepository<Long, User> repoUser = new InMemoryRepository<>(new UserValidator());

//        UserFileRepository repoUser = new UserFileRepository("data/Users.csv", new UserValidator());
//        FriendshipFileRepository repoFriendship = new FriendshipFileRepository("data/Friendships.csv", new FriendshipValidator(repoUser));
        UserDBRepository userDBRepository = new UserDBRepository(new UserValidator());
        InMemoryRepository<Long, Friendship> repoFriendship = new InMemoryRepository<>(new FriendshipValidator(userDBRepository));

        userDBRepository.findAll().forEach(System.out::println);

        SocialNetwork socialNetwork = new SocialNetwork(userDBRepository, repoFriendship);
        Console ui = new Console(socialNetwork);


        ui.run();
    }
}

