package domain;


import java.util.*;

public class User extends Entity<Long> {
    private String firstName;
    private String lastName;
//    List<User> friends;

    public User(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
//        friends = new Vector<User>();
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

//    public void addFriend(User user) {
//        friends.add(user);
//    }
//
//    public void removeFriend(User user) {
//        friends.remove(user);
//    }
//
//    public List<User> getFriends() {
//        return friends;
//    }

    @Override
    public String toString() {
        return "Utilizator{" +
                "firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", friends=" + +
                '}';
    }

//    @Override
//    public boolean equals(Object o) {
//        if (this == o) return true;
//        if (!(o instanceof User)) return false;
//        User that = (User) o;
//        return getFirstName().equals(that.getFirstName()) &&
//                getLastName().equals(that.getLastName()) &&
//                getFriends().equals(that.getFriends());
//    }
//
//    @Override
//    public int hashCode() {
//        return Objects.hash(getFirstName(), getLastName(), getFriends());
//    }


}