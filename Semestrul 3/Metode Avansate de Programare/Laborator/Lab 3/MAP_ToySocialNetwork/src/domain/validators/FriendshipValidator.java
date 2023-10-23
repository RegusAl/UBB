package domain.validators;

import domain.Friendship;
import domain.User;
import repository.InMemoryRepository;
import repository.Repository;

public class FriendshipValidator implements Validator<Friendship> {

    private InMemoryRepository<Long, User> repo;

    public FriendshipValidator(InMemoryRepository<Long, User> repo) {
        this.repo = repo;
    }

    @Override
    public void validate(Friendship entity) throws ValidationException {

    }
}
