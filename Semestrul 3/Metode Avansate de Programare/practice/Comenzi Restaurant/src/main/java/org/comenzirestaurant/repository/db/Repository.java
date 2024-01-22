package org.comenzirestaurant.repository.db;

import com.example.restaurante.domain.Entity;
import com.example.restaurante.exceptions.InexistentEntityException;

import java.util.Map;

/**
 * CRUD operations repository interface
 * @param <ID> - type E must have an attribute of type ID
 * @param <E> -  type of entities saved in repository
 */
public interface Repository<ID, E extends Entity<ID>> {

    /**
     * Returns the entity that has the given id
     * @param id ID - the id of the entity to be returned
     *           id must not be null
     * @return the entity with the specified id
     * @throws IllegalArgumentException if the id is null.
     * @throws InexistentEntityException if there is no entity with the given id
     */
    E find(ID id) throws IllegalArgumentException;

    /**
     * Returns all entities in the repository
     * @return - an iterable object that contains all entities
     */
    Iterable<E> getAll();

    /**
     * Method that returns the map of the objects
     * @return a map object with all entities from the repository
     */
    public Map<ID, E> getMap();

    /**
     * Clears the repository's data
     */
    void clear();
}
