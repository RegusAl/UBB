package map.toysocialnetwork;


import map.toysocialnetwork.domain.validators.FriendshipValidator;
import map.toysocialnetwork.domain.validators.UserValidator;
import map.toysocialnetwork.repository.database.FriendshipDBRepository;
import map.toysocialnetwork.repository.database.UserDBRepository;
import map.toysocialnetwork.service.SocialNetwork;
import map.toysocialnetwork.ui.Console;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Main {

    public static void main(String[] args) {

        UserDBRepository userDBRepository = new UserDBRepository(new UserValidator());
        FriendshipDBRepository friendshipDBRepository = new FriendshipDBRepository(new FriendshipValidator(userDBRepository));

        SocialNetwork socialNetwork = new SocialNetwork(userDBRepository, friendshipDBRepository);

        Console ui = new Console(socialNetwork);


        ui.run();
    }
}

