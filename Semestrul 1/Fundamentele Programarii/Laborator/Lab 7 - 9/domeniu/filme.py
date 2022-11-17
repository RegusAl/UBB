class Film:

    def __init__(self, id_film, nume_film, gen_film):
        self.__id_film = id_film
        self.__nume_film = nume_film
        self.__gen_film = gen_film

    def creare_film(self):
        # film = {'id': self.__id_film, 'nume': self.__nume_film, 'gen': self.__gen_film}
        film = [self.__id_film, self.__nume_film, self.__gen_film]
        return film

    def set_nume(self, nume_film):
        self.__nume_film = nume_film

    def set_gen(self, gen_film):
        self.__gen_film = gen_film

    def __eq__(self, other):
        return self.__id_film == other.__id_film

    # def film_creat(self):
    #     return [self.__id_film, self.__nume_film, self.__gen_film]

def get_id_film(film):
        return film[0]

def get_nume_film(film):
        return film[1]

def get_gen_film(film):
        return film[2]
