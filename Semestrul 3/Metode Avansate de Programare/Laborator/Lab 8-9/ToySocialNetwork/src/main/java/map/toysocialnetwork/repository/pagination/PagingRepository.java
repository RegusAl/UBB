package map.toysocialnetwork.repository.pagination;

import map.toysocialnetwork.domain.Entity;
import map.toysocialnetwork.repository.Repository;

public interface PagingRepository<ID, E extends Entity<ID>> extends Repository<ID, E> {
    Page<E> findall(Pageable pageable);
}
