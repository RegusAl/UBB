namespace sem11.domain.validators;
    class SarcinaValidator : IValidator<Sarcina>
    {
        public void Validate(Sarcina e)
        {
            bool valid = true;
            if (valid == false)
            {
                throw new ValidationException("Obiectul nu e valid");
            }
        }
    }

