package ro.ubbcluj.cs.map.socialnetwork.domain.validators;



import ro.ubbcluj.cs.map.socialnetwork.domain.Friendship;

import java.util.Objects;

public class FriendshipValidator implements Validator<Friendship> {

    @Override
    public void validate(Friendship entity) throws ValidationException {
        if (Objects.equals(entity.getUser1Id(), entity.getUser2Id()))
            throw new ValidationException("Error - the IDs are identical");
    }
}
