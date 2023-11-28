package domain;

import java.util.Comparator;

public class Sortbyname implements Comparator<Student> {

    public int compare(Student a, Student b) {
        return a.getNume().compareTo(b.getNume());
    }
}
