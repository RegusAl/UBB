using sem11.domain;
using sem11.domain.validators;

namespace sem11.repository;


class InMemoryRepository<ID, E> : IRepository<ID, E> where E : Entity<ID>
{
    protected IValidator<E> vali;

    protected IDictionary<ID, E> entities = new Dictionary<ID, E>();

    public InMemoryRepository(IValidator<E> vali)
    {
        this.vali = vali;
    }

    public E Delete(ID id)
    {
        throw new NotImplementedException();
    }

    public IEnumerable<E> FindAll()
    {
        return entities.Values.ToList<E>();
    }

    public E FindOne(ID id)
    {
        throw new NotImplementedException();
    }

    public E Save(E entity)
    {
        if (entity == null)
            throw new ArgumentNullException("entity must not be null");
        this.vali.Validate(entity);
        if (this.entities.ContainsKey(entity.Id))
        {
            return entity;
        }

        this.entities[entity.Id] = entity;
        return default(E);
    }

    public E Update(E entity)
    {
        throw new NotImplementedException();
    }
}

