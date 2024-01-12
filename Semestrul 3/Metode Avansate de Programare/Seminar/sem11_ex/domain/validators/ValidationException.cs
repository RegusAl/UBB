namespace sem11.domain.validators;

class ValidationException : ApplicationException
{
    public ValidationException(String message) : base(message)
    {
    }
}

