using sem11.domain;
using sem11.repository;

namespace sem11.service;

class SarcinaService
{
    private IRepository<string, Sarcina> repo;

    public SarcinaService(IRepository<string, Sarcina> repo)
    {
        this.repo = repo;
    }



    public List<Sarcina> FindAllSarcini()
    {
        return repo.FindAll().ToList();
    }
}
