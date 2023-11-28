package org.example;

import org.example.domain.User;
import org.example.repository.Repository;
import org.example.repository.UserDBRepository;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

        String url="jdbc:postgresql://localhost:5435/socialnetwork";
        String username = "albert";
        String password = "admin";

        Repository<Long, User> userRepository = new UserDBRepository(url, username, password);
        //userRepository.findAll().forEach(System.out::println);
        System.out.println(userRepository.findOne(1L));



    }
}