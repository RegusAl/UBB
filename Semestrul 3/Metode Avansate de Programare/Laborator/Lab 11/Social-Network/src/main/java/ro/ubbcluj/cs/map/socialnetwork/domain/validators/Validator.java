package ro.ubbcluj.cs.map.socialnetwork.domain.validators;

public interface Validator<T> {
    void validate(T entity) throws ValidationException;
}

