package ro.ubbcluj.cs.map.socialnetwork.domain;

import java.time.LocalDateTime;
import java.util.Objects;

public class Friendship extends Entity<Long> {
    private Long user1Id;
    private Long user2Id;

    private String nameUser1;
    private String nameUser2;
    LocalDateTime friendsFrom;
    private FriendRequest friendRequestStatus;

    public Friendship(Long user1Id, Long user2Id) {
        this.user1Id = user1Id;
        this.user2Id = user2Id;
        this.friendsFrom = LocalDateTime.now();
        this.friendRequestStatus = FriendRequest.PENDING;
    }

    public Friendship(User user1, User user2) {
        this.user1Id = user1.getId();
        this.user2Id = user2.getId();
        this.friendsFrom = LocalDateTime.now();
        this.friendRequestStatus = FriendRequest.PENDING;
    }

    public Friendship(Long user1Id, Long user2Id, LocalDateTime friendsFrom) {
        this.user1Id = user1Id;
        this.user2Id = user2Id;
        this.friendsFrom = friendsFrom;
        this.friendRequestStatus = FriendRequest.PENDING;
    }

    public Friendship(Long user1Id, Long user2Id, FriendRequest friendRequestStatus) {
        this.user1Id = user1Id;
        this.user2Id = user2Id;
        this.friendsFrom = LocalDateTime.now();
        this.friendRequestStatus = friendRequestStatus;
    }

    public Friendship(Long user1Id, Long user2Id, LocalDateTime friendsFrom, FriendRequest friendRequestStatus) {
        this.user1Id = user1Id;
        this.user2Id = user2Id;
        this.friendsFrom = friendsFrom;
        this.friendRequestStatus = friendRequestStatus;
    }

    public Long getUser1Id() {
        return user1Id;
    }

    public void setUser1Id(Long user1Id) {
        this.user1Id = user1Id;
    }

    public Long getUser2Id() {
        return user2Id;
    }

    public void setUser2Id(Long user2Id) {
        this.user2Id = user2Id;
    }

    public LocalDateTime getFriendsFrom() {
        return friendsFrom;
    }

    public void setFriendsFrom(LocalDateTime friendsFrom) {
        this.friendsFrom = friendsFrom;
    }

    public FriendRequest getFriendRequestStatus() {
        return friendRequestStatus;
    }

    public void setFriendRequestStatus(FriendRequest friendRequestStatus) {
        this.friendRequestStatus = friendRequestStatus;
    }

    public void setNameUser1(String nameUser1) {
        this.nameUser1 = nameUser1;
    }

    public void setNameUser2(String nameUser2) {
        this.nameUser2 = nameUser2;
    }

    @Override
    public String toString() {
        return "FROM: " + this.nameUser1 +
                " ,TO: " + this.nameUser2 +
                " ,STATUS: " + friendRequestStatus;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Friendship that = (Friendship) o;
        return Objects.equals(user1Id, that.user1Id) && Objects.equals(user2Id, that.user2Id) ||
                Objects.equals(user1Id, that.user2Id) && Objects.equals(user2Id, that.user1Id);
    }

    @Override
    public int hashCode() {
        return Objects.hash(user1Id, user2Id);
    }
}
