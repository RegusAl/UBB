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

        User u1 = repo.findOne(entity.getIdUser1());
        User u2 = repo.findOne(entity.getIdUser2());

        if (entity.getIdUser1() == null || entity.getIdUser2() == null)
            throw new ValidationException("The id can't be null! ");
        if (u1 == null || u2 == null)
            throw new ValidationException("The id doesn't exist! ");
    }
}
