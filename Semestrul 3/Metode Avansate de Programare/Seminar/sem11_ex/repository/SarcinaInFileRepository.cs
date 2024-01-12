using sem11.domain;
using sem11.domain.validators;

namespace sem11.repository;


class SarcinaInFileRepository : InFileRepository<string, Sarcina>
{

    public SarcinaInFileRepository(IValidator<Sarcina> vali, string fileName) : base(vali, fileName,
        EntityToFileMapping.CreateSarcina)
    {

    }

}