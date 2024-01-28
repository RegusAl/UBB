package ro.ubbcluj.cs.map.socialnetwork.repository;


import ro.ubbcluj.cs.map.socialnetwork.domain.Entity;

public interface PagingRepository<ID, E extends Entity<ID>> extends Repository<ID, E> {
    Page<E> findAll(Pageable pageable);
}
