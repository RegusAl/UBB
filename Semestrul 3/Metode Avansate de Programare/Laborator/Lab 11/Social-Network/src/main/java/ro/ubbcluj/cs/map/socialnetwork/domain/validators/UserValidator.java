package ro.ubbcluj.cs.map.socialnetwork.domain.validators;


import ro.ubbcluj.cs.map.socialnetwork.domain.User;

import java.util.Objects;

public class UserValidator implements Validator<User> {

    @Override
    public void validate(User entity) throws ValidationException {
        validateFirstName(entity.getFirstName());
        validateLastName(entity.getLastName());
        validateEmail(entity.getEmail());
    }


    private void validateFirstName(String name) throws ValidationException {
        if (name == null) // Check if it's null
            throw new ValidationException("Invalid name - it is null; ");
        else if (Objects.equals(name, "")) // Check if it's empty
            throw new ValidationException("Invalid name - first name is null; ");
        else if (name.isEmpty()) // Check if it's empty
            throw new ValidationException("Invalid name - first name is empty; ");
        else if (name.length() > 50) // Check if it is too long
            throw new ValidationException("Invalid name - first name is too long; ");
        else if (!name.matches("[a-zA-Z]+"))
            throw new ValidationException("Invalid name - first name must contain only letters");
    }

    private void validateLastName(String name) throws ValidationException {
        if (name == null) // Check if it's null
            throw new ValidationException("Invalid name - it is null; ");
        else if (Objects.equals(name, "")) // Check if it's empty
            throw new ValidationException("Invalid name - first name is null; ");
        else if (name.isEmpty()) // Check if it's empty
            throw new ValidationException("Invalid name - first name is empty; ");
        else if (name.length() > 50) // Check if it is too long
            throw new ValidationException("Invalid name - first name is too long; ");
        else if (!name.matches("[a-zA-Z]+"))
            throw new ValidationException("Invalid name - first name must contain only letters");
    }

    private void validateEmail(String email) throws ValidationException {
        if (email == null) // Check if it's null
            throw new ValidationException("Invalid email - it is null; ");
        else if (Objects.equals(email, "")) // Check if it's empty
            throw new ValidationException("Invalid email - it is null; ");
        else if (email.isEmpty()) // Check if it's empty
            throw new ValidationException("Invalid email - it is empty; ");
        else if (email.length() > 50) // Check if it is too long
            throw new ValidationException("Invalid email - it is too long; ");
        else if (email.length() < 3) // Check if it is too long
            throw new ValidationException("Invalid email - it is too short; ");
        else if (!email.matches("^[a-zA-Z0-9-_]+@[a-zA-Z0-9-_]+\\.[a-zA-Z0-9-_]+$"))
            throw new ValidationException("Invalid email syntax - special characters accepted - and _");
    }

}
