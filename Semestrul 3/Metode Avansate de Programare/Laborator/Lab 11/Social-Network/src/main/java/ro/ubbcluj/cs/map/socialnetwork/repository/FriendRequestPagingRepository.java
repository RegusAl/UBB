package ro.ubbcluj.cs.map.socialnetwork.repository;


import ro.ubbcluj.cs.map.socialnetwork.domain.Entity;

public interface FriendRequestPagingRepository<ID, E extends Entity<ID>> extends PagingRepository<ID, E>{
    Page<E> findAllFriendRequests(Pageable pageable);

    Page<E> findAllUserFriends(Pageable pageable, Long id);

    Page<E> findAllUserFriendRequests(Pageable pageable, Long id);
}
