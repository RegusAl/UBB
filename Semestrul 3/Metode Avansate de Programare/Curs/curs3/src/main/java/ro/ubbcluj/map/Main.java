package ro.ubbcluj.map;

import ro.ubbcluj.map.domain.Utilizator;
import ro.ubbcluj.map.domain.validators.UtilizatorValidator;
import ro.ubbcluj.map.repository.InMemoryRepository;

public class Main {

    public static void main(String[] args) {

        Utilizator u1=new Utilizator("u1FirstName", "u1LastName");
        u1.setId(1l);
        Utilizator u2=new Utilizator("u2FirstName", "u2LastName"); u2.setId(1l);
        Utilizator u3=new Utilizator("u3FirstName", "u3LastName"); u3.setId(1l);
        Utilizator u4=new Utilizator("u4FirstName", "u4LastName"); u4.setId(1l);
        Utilizator u5=new Utilizator("u5FirstName", "u5LastName"); u5.setId(1l);
        Utilizator u6=new Utilizator("u6FirstName", "u6LastName"); u6.setId(1l);
        Utilizator u7=new Utilizator("u7FirstName", "u7LastName"); u7.setId(1l);

        InMemoryRepository<Long, Utilizator> repo=new InMemoryRepository<>(new UtilizatorValidator());
        repo.save(u1);
        repo.save(u2);
        repo.save(u3);
        repo.save(u4);
        repo.save(u5);
        repo.save(u6);
        repo.save(u7);

        System.out.println("ok");
    }
}
