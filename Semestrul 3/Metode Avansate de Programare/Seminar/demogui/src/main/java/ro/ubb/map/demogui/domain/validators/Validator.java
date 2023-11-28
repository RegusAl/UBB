package ro.ubb.map.demogui.domain.validators;

public interface Validator<T> {
    void validate(T entity) throws ValidationException;
}
