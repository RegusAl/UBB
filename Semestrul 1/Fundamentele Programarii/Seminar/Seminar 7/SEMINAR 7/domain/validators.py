from domain.entities import Serial


class ValidationException(Exception):
    pass


class ShowValidator:
    def validate(self, show):
        errors = []
        if len(show.getTitle()) < 2:
            errors.append('Titlul serialului trebuie sa aiba mai mult de 2 caractere.')
        if show.getAnAparitie() < 1970 or show.getAnAparitie() > 2022:
            errors.append('Anul aparitiei trebuie sa fie intre 1970-2022.')
        if show.getEpisoade() < 0:
            errors.append('Numarul de episoade trebuie sa fie mai mare de 0.')

        if len(errors) > 0:
            errors_string = '\n'.join(errors)
            raise ValueError(errors_string)


def test_show_validator():
    test_validator = ShowValidator()
    show1 = Serial('1', 'See', 2019, 12)
    test_validator.validate(show1)
    show2 = Serial('2', '', 2050, 55)

    try:
        test_validator.validate(show2)
        assert False
    except ValueError:
        assert True

    show3 = Serial('3', 'See', 2019, -55)
    try:
        test_validator.validate(show3)
        assert False
    except ValueError:
        assert True
