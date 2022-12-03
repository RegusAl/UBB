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



