package ro.ubbcluj.cs.map.socialnetwork.domain;

import java.util.Objects;

public class User extends Entity<Long>{
    private String firstName;
    private String lastName;
    private String email;
    private String password;

    public User(String firstName, String lastName, String email) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.email = email;
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

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String encryptPassword(int shift) {
        StringBuilder result = new StringBuilder();
        password = this.password;
        for (int i = 0; i < password.length(); i++) {
            char ch = password.charAt(i);

            if (Character.isLetter(ch)) {
                char base = (Character.isUpperCase(ch)) ? 'A' : 'a';
                result.append((char) ((ch - base + shift) % 26 + base));
            } else {
                result.append(ch);
            }
        }

        return result.toString();
    }

    public String decryptPassword(int shift) {
        StringBuilder result = new StringBuilder();
        password = this.password;

        return encryptPassword(26-shift);
    }

//    public String encryptPassword() {
//        StringBuilder result = new StringBuilder();
//        for (Character c : this.password.toCharArray()) {
//            result.append(c);
//            if (isVowel(c)) {
//                result.append('p').append(c);
//            }
//        }
//
//        return result.toString();
//    }
//
//    public String decryptPassword() {
//        StringBuilder result = new StringBuilder();
//        for (int i = 0; i < this.password.length(); i++) {
//            char c = this.password.charAt(i);
//            result.append(c);
//            if (isVowel(c)) {
//                i += 2;
//            }
//        }
//
//        return result.toString();
//    }



    @Override
    public String toString() {
        return  "id='" + id + '\'' +
                "firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", email='" + email + '\'';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof User)) return false;
        User that = (User) o;
        return id.equals(that.getId());
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), firstName, lastName, email);
    }

}
