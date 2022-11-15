from erori.repo_error import RepoError
class RepoClienti:

    def __init__(self):
        self.__clienti = [
            [1, "Mihai Ion", 5030724668945],
            [2, "Alexandru Popescu", 6023115705789],
            [3, "Mihaela Sandu", 3201343245673],
            [4, "Mihai Eminescu", 1234115678901]
        ]

    def adauga_client(self, client):
        for el in self.__clienti:
            if el[0] == client[0]:
                raise RepoError("Client existant!")
        self.__clienti.append(client)

    def afisare_clienti(self):
        return self.__clienti