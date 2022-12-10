from erori.validation_error import ValidError
# from domeniu.filme import get_id_film, get_nume_film, get_gen_film

class ValidatorFilme:

    def __init__(self):
        pass

    def valideaza(self, film):
        erori = ""
        if film.get_id_film()<0 or film.get_id_film()=="":
            erori += "id invalid!\n"
        if film.get_nume_film()=="":
            erori += "nume invalid\n"
        if film.get_gen_film()=="":
            erori += "gen invalid\n"
        if len(erori)>0:
            raise ValidError(erori)

