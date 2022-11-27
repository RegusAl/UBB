from erori.validation_error import ValidError
#from domeniu.clienti import Client
class ValidatorClienti:

    def __init__(self):
        pass

    def valideaza(self, client):
        erori = ""
        if client.get_id_client() < 0 or client.get_id_client()=="":
            erori += "id invalid!\n"
        if client.get_nume_client() == "":
            erori += "nume invalid!\n"
        if client.get_cnp_client() < 0 or client.get_cnp_client()=="" or len(str(client.get_cnp_client()))!=13:
            erori += "cnp invalid!\n"
        if len(erori) > 0:
            raise ValidError(erori)

