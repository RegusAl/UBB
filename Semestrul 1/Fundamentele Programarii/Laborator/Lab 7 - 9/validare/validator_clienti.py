from erori.validation_error import ValidError
class ValidatorClienti:

    def __init__(self):
        pass

    def valideaza(self, client):
        erori = ""
        if client[0] < 0 or client[0]=="":
            erori += "id invalid!\n"
        if client[1] == "":
            erori += "nume invalid!\n"
        if client[2] < 0:
            erori += "cnp invalid!\n"
        if len(erori) > 0:
            raise ValidError(erori)

