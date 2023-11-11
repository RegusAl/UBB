

import domain.Friendship;
import domain.User;
import domain.validators.FriendshipValidator;
import domain.validators.UserValidator;
import repository.FriendshipFileRepository;
import repository.InMemoryRepository;
import repository.Repository;
import repository.UserFileRepository;
import repository.database.FriendshipDBRepository;
import repository.database.UserDBRepository;
import service.SocialNetwork;
import ui.Console;

import java.util.Optional;

public class Main {

    public static void main(String[] args) {

        UserDBRepository userDBRepository = new UserDBRepository(new UserValidator());
        FriendshipDBRepository friendshipDBRepository = new FriendshipDBRepository(new FriendshipValidator(userDBRepository));

//        InMemoryRepository<Long, Friendship> repoFriendship = new InMemoryRepository<>(new FriendshipValidator(userDBRepository));

//        long x = 1;
//        Optional<User> user1 = userDBRepository.findOne(x);
//        System.out.println(user1);

        SocialNetwork socialNetwork = new SocialNetwork(userDBRepository, friendshipDBRepository);

        Console ui = new Console(socialNetwork);


        ui.run();
    }
}

