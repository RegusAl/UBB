using sem11.domain;
using sem11.domain.validators;

namespace sem11.repository;

class AngajatInFileRepository : InFileRepository<string, Angajat>
{

    public AngajatInFileRepository(IValidator<Angajat> vali, string fileName) : base(vali, fileName,
        EntityToFileMapping.CreateAngajat)
    {

    }

}

