

import domain.validators.FriendshipValidator;
import domain.validators.UserValidator;
import repository.database.FriendshipDBRepository;
import repository.database.UserDBRepository;
import service.SocialNetwork;
import ui.Console;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Main {

    public static void main(String[] args) {

//        System.out.println(LocalDateTime.now().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")));
//
//        System.out.println(LocalDateTime.now().getMonth().toString());



        UserDBRepository userDBRepository = new UserDBRepository(new UserValidator());
        FriendshipDBRepository friendshipDBRepository = new FriendshipDBRepository(new FriendshipValidator(userDBRepository));

        SocialNetwork socialNetwork = new SocialNetwork(userDBRepository, friendshipDBRepository);

        Console ui = new Console(socialNetwork);


        ui.run();
    }
}

