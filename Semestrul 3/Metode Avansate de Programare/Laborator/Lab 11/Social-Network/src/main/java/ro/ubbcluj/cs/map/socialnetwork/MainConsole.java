package ro.ubbcluj.cs.map.socialnetwork;


import ro.ubbcluj.cs.map.socialnetwork.console.ConsoleUI;
import ro.ubbcluj.cs.map.socialnetwork.domain.Friendship;
import ro.ubbcluj.cs.map.socialnetwork.domain.Message;
import ro.ubbcluj.cs.map.socialnetwork.domain.User;
import ro.ubbcluj.cs.map.socialnetwork.domain.validators.FriendshipValidator;
import ro.ubbcluj.cs.map.socialnetwork.domain.validators.UserValidator;
import ro.ubbcluj.cs.map.socialnetwork.repository.*;
import ro.ubbcluj.cs.map.socialnetwork.service.Service;

public class MainConsole {
    public static void main(String[] args) {
        String url = args[0];
        String username = args[1];
        String password = args[2];

        PagingRepository<Long, User> userRepo = new UserDBRepository(url, username, password, new UserValidator());
        FriendRequestPagingRepository<Long, Friendship> friendshipRepo = new FriendshipDBRepository(url, username, password, new FriendshipValidator());
        MessagePagingRepository<Long, Message> messageRepo = new MessageDBRepository(url, username, password, userRepo);
        Service service = new Service(userRepo, friendshipRepo, messageRepo);
        ConsoleUI console = new ConsoleUI(service);

        console.run();
    }
}
