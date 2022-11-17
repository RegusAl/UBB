from erori.validation_error import ValidError
from domeniu.filme import get_id_film, get_nume_film, get_gen_film


class ValidatorFilme:

    def __init__(self):
        pass

    def valideaza(self, film):
        erori = ""
        if get_id_film(film)<0:
            erori += "id invalid!\n"
        if get_nume_film(film)=="":
            erori += "nume invalid\n"
        if get_gen_film(film)=="":
            erori += "gen invalid\n"
        if len(erori)>0:
            raise ValidError(erori)

