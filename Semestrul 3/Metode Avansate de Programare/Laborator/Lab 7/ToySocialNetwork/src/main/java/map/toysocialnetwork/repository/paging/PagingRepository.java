package map.toysocialnetwork.repository.paging;

public interface PagingRepository<ID ,
        E extends Entity<ID>>
        extends CrudRepository<ID, E> {

    Page<E> findAll(Pageable pageable);   // Pageable e un fel de paginator
}
