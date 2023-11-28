package org.example;

import domain.Sortbyname;
import domain.Student;

import java.util.Comparator;
import java.util.HashSet;
import java.util.TreeSet;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Dan", 4.5f);
        Student s2 = new Student("Ana", 8.5f);
        Student s3 = new Student("Dan", 4.5f);
        Student s4 = new Student("Bogdan", 5.7f);

        // Hash set
        HashSet<Student> students = new HashSet<Student>();
        students.add(s1);
        students.add(s2);
        students.add(s3);
        students.forEach(System.out::println);
        //Fara a implementa equals si hash code adauga atat s1 cat si s3 in hash set.
        // Cu metodele implementate adauga doar 2

        // Tree set
        TreeSet<Student> studentTreeSet = new TreeSet<Student>(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o1.getNume().compareTo(o2.getNume());
            }
        });

        System.out.println("Ordonati dupa nume");
        studentTreeSet.add(s1);
        studentTreeSet.add(s2);
        studentTreeSet.add(s3);
        studentTreeSet.add(s4);
        studentTreeSet.forEach(System.out::println);

        TreeSet<Student> studentTreeSetMedie = new TreeSet<Student>(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return (int) (o1.getMedie() - o2.getMedie());
            }
        });

        System.out.println("Ordonati dupa medie");
        studentTreeSetMedie.add(s1);
        studentTreeSetMedie.add(s2);
        studentTreeSetMedie.add(s3);
        studentTreeSetMedie.add(s4);
        studentTreeSetMedie.forEach(System.out::println);


    }
}