package map.toysocialnetwork.service;

import map.toysocialnetwork.domain.Friendship;
import map.toysocialnetwork.domain.User;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class SocialCommunities {

    SocialNetwork socialNetwork;
    HashMap<Long, List<Long>> adjList;

    public SocialCommunities(SocialNetwork socialNetwork) {
        this.socialNetwork = socialNetwork;
    }

    void DFS(Long v, HashMap<Long, Boolean> visited) {
        visited.put(v, true);
        System.out.println(v + " " + socialNetwork.findUser(v).getFirstName() + " " + this.socialNetwork.findUser(v).getLastName());
        if (adjList.containsKey(v)) {
            adjList.get(v).stream().filter(x -> !visited.containsKey(x)).forEach(x -> DFS(x, visited));
        }
    }

    public int connectedCommunities() {
        // creates an adjency list of user and its friends
        adjList = new HashMap<Long, List<Long>>();
        socialNetwork.getUsers().forEach(user -> {
            List<Long> friends = new ArrayList<>();
            socialNetwork.getFriendships().forEach(friendship -> {
                if (friendship.getIdUser1().equals(user.getId()))
                    friends.add(friendship.getIdUser2());
                if (friendship.getIdUser2().equals(user.getId()))
                    friends.add(friendship.getIdUser1());
            });
            if (!friends.isEmpty())
                this.adjList.put(user.getId(), friends);
        });

        // list of ids of users
        List<Long> ids = new ArrayList<>();
        socialNetwork.getUsers().forEach(user -> {
            ids.add(user.getId());
        });
        int nrOfCommunities = 0;
//        if(ids.size() == 1)
//            return 1;
        HashMap<Long, Boolean> visited = new HashMap<Long, Boolean>();
        for (Long v : ids) {
            if (!visited.containsKey(v)) {
                DFS(v, visited);
                nrOfCommunities++;
                System.out.println();
            }
        }
        return nrOfCommunities;
    }

    public List<Long> mostSocialCommunity() {
        // creates an adjency list of user and its friends
        adjList = new HashMap<Long, List<Long>>();
        List<Long> max = new ArrayList<>();
        for (User user : socialNetwork.getUsers()) {
            List<Long> friends = new ArrayList<>();
            for (Friendship friendship : socialNetwork.getFriendships()) {
                if (friendship.getIdUser1().equals(user.getId()))
                    friends.add(friendship.getIdUser2());
                if (friendship.getIdUser2().equals(user.getId()))
                    friends.add(friendship.getIdUser1());
            }
            if (!friends.isEmpty()) {
                this.adjList.put(user.getId(), friends);
                if (max.size() < friends.size() + 1) {
                    max = friends;
                    max.add(user.getId());
                }
            }
        }
//        System.out.println(adjList.values());
//        System.out.println(max);
        return max;
    }
}
