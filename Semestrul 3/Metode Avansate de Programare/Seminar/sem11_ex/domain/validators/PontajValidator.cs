namespace sem11.domain.validators;

class PontajValidator : IValidator<Pontaj>
{
    public void Validate(Pontaj e)
    {
        bool valid = true;
        if (valid == false)
        {
            throw new ValidationException("Obiectul nu e valid");
        }
    }
}

