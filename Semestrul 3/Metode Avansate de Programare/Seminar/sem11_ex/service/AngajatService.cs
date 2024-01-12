
using sem11.domain;
using sem11.repository;

namespace sem11.service;

class AngajatService
{
    private IRepository<string, Angajat> repo;

    public AngajatService(IRepository<string, Angajat> repo)
    {
        this.repo = repo;
    }


    public List<Angajat> FindAllAngajati()
    {
        return repo.FindAll().ToList();
    }
}

