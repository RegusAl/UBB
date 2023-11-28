package ro.ubb.map.demogui.repository.paging;


import ro.ubb.map.demogui.domain.Entity;
import ro.ubb.map.demogui.repository.CrudRepository;

public interface PagingRepository<ID ,
        E extends Entity<ID>>
        extends CrudRepository<ID, E> {

    Page<E> findAll(Pageable pageable);   // Pageable e un fel de paginator
}
