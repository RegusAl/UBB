from erori.validation_error import ValidError
from domeniu.clienti import get_id_client, get_nume_client, get_cnp_client
class ValidatorClienti:

    def __init__(self):
        pass

    def valideaza(self, client):
        erori = ""
        if get_id_client(client) < 0 or get_id_client(client)=="":
            erori += "id invalid!\n"
        if get_nume_client(client) == "":
            erori += "nume invalid!\n"
        if get_cnp_client(client) < 0 or get_cnp_client(client)=="":
            erori += "cnp invalid!\n"
        if len(erori) > 0:
            raise ValidError(erori)

