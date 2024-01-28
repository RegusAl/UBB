using Facturi.Domain;

namespace Facturi.Repository;

public interface IFileRepository<ID, E> : IRepository<ID, E> where E : Entity<ID> 
{
    string file { set; get; }
    
    void GetFromFile();
}