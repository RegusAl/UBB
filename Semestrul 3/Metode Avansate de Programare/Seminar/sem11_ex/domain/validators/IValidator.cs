namespace sem11.domain.validators;

interface IValidator<E>
{
    void Validate(E e);
}

