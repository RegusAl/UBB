package org.examen.repository;

import com.example.model.domain.Persoana;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;

public interface Repository<ID,E> {
    E findOne(ID id);
    E findByUsername(String username);

    List<E> findAll();

    void save(E elem);
}
