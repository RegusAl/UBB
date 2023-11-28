package ro.ubb.map.demogui.repository;


import ro.ubb.map.demogui.domain.Entity;
import ro.ubb.map.demogui.domain.validators.Validator;
import ro.ubb.map.demogui.repository.paging.Page;
import ro.ubb.map.demogui.repository.paging.Pageable;
import ro.ubb.map.demogui.repository.paging.Paginator;
import ro.ubb.map.demogui.repository.paging.PagingRepository;


import java.util.HashMap;
import java.util.Map;

public class InMemoryRepository<ID , E extends Entity<ID>> implements PagingRepository<ID,E> {

    private Validator<E> validator;
    Map<ID,E> entities;

    public InMemoryRepository(Validator<E> validator) {
        this.validator = validator;
        entities=new HashMap<ID,E>();
    }

    @Override
    public E findOne(ID id){
        if (id==null)
            throw new IllegalArgumentException("id must be not null");
        return entities.get(id);
    }

    @Override
    public Iterable<E> findAll() {
        return entities.values();
    }

    @Override
    public E save(E entity) {
        if (entity==null)
            throw new IllegalArgumentException("entity must be not null");
        validator.validate(entity);
        if(entities.get(entity.getId()) != null) {
            return entity;
        }
        entities.put(entity.getId(),entity);
        return null;
    }

    @Override
    public E delete(ID id) {
        return entities.remove(id);
    }

    @Override
    public E update(E entity) {
        if(entity == null)
            throw new IllegalArgumentException("entity must be not null!");
        validator.validate(entity);
        if(entities.get(entity.getId()) != null) {
            entities.put(entity.getId(),entity);
            return null;
        }
        return entity;

    }

    @Override
    public Page<E> findAll(Pageable pageable) {
        Paginator<E> paginator = new Paginator<E>(pageable, this.findAll());
        return paginator.paginate();
    }
}
