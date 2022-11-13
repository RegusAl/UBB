from erori.validation_error import ValidError


class ValidatorFilme:

    def __init__(self):
        pass

    def valideaza(self, film):
        erori = ""
        if film[0]<0:
            erori += "id invalid!\n"
        if film[1]=="":
            erori += "nume invalid\n"
        if film[2]=="":
            erori += "gen invalid\n"
        if len(erori)>0:
            raise ValidError(erori)

