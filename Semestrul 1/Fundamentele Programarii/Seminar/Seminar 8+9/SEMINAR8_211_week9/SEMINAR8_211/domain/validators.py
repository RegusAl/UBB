from domain.entities import Serial, Client, Rating
from exceptions.exceptions import ValidationException


class ShowValidator:
    def validate(self, show):
        errors = []
        if len(show.getTitle()) < 2:
            errors.append('Titlul serialului trebuie sa aiba mai mult de 2 caractere.')
        if show.getAnAparitie() < 1970 or show.getAnAparitie() > 2021:
            errors.append('Anul aparitiei trebuie sa fie intre 1970-2021.')
        if show.getEpisoade() < 0:
            errors.append('Numarul de episoade trebuie sa fie mai mare de 0.')

        if len(errors) > 0:
            errors_string = '\n'.join(errors)
            raise ValidationException(errors_string)


def test_show_validator():
    test_validator = ShowValidator()
    show1 = Serial('1', 'See', 2019, 12)
    test_validator.validate(show1)
    show2 = Serial('2', '', 2050, 55)

    try:
        test_validator.validate(show2)
        assert False
    except ValidationException:
        assert True

    show3 = Serial('3', 'See', 2019, -55)
    try:
        test_validator.validate(show3)
        assert False
    except ValidationException:
        assert True


class ClientValidator:
    def validate(self, client):
        errors = []
        if len(client.getNume()) < 2:
            errors.append('Numele clientului trebuie sa aiba mai mult de 2 caractere.')

        if client.getVarsta() < 18 or client.getVarsta() > 110:
            errors.append('Varsta trebuie sa fie cuprinsa intre 18-110.')

        if len(errors) > 0:
            # errors_string = '\n'.join(errors)
            raise ValidationException(errors)


class RatingValidator:
    def validate(self, rating):
        errors = []
        if rating.getNoStars() < 0 or rating.getNoStars() > 5:
            errors.append('Rating-ul poate fi intre 1 si 5.')

        if len(errors) > 0:
            # errors_string = '\n'.join(errors)
            raise ValidationException(errors)


def test_rating_validator():
    show = Serial('SF123', 'See', 2019, 12)
    client = Client('1', 'Ianis', 26)

    rating = Rating(show, client, 4.1)

    validator = RatingValidator()
    validator.validate(rating)

    rating1 = Rating(show, client, 100)
    try:
        validator.validate(rating1)
        assert False
    except ValidationException:
        assert True


