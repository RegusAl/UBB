package org.exemplu226.repository;

import com.example.rezerva.domain.Entity;
import com.example.rezerva.domain.exceptions.ValidationException;

import java.util.List;

public interface Repository<E> {

    List<E> getAll();
}
