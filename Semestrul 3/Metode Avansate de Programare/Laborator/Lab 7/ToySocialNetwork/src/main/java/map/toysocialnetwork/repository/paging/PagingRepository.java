package map.toysocialnetwork.repository.paging;

import map.toysocialnetwork.domain.Entity;
import map.toysocialnetwork.repository.CrudRepository;

public interface PagingRepository<ID ,
        E extends Entity<ID>>
        extends CrudRepository<ID, E> {

    Page<E> findAll(Pageable pageable);   // Pageable e un fel de paginator
}
