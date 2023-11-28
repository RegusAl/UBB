package domain;

import java.util.Objects;

public class Student {

    private float medie;
    private String nume;

    public Student(String nume, float medie) {
        this.medie = medie;
        this.nume = nume;
    }

    @Override
    public String toString() {
        return "Student{" +
                "nume=" + nume +
                ", medie='" + medie + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return Float.compare(medie, student.medie) == 0 && Objects.equals(nume, student.nume);
    }

    @Override
    public int hashCode() {
        return Objects.hash(medie, nume);
    }

    public float getMedie() {
        return medie;
    }

    public void setMedie(float medie) {
        this.medie = medie;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

}
