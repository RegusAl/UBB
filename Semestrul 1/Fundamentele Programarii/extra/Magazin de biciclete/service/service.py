class Service:

    def __init__(self, repository):
        self.__repository = repository

    def get_all(self):
        return self.__repository.get_all()

    def sterge_tip(self, tip):
        for el in self.get_all():
            if el.get_tip() == tip:
                self.__repository.delete(el.get_id_bicicleta())

    def sterge_max(self):
        produse = self.get_all()
        produse.sort(key = lambda x:x.get_pret(), reverse = True)
        max = produse[0].get_pret()
        for el in produse:
            if el.get_pret() == max:
                self.__repository.delete(el.get_id_bicicleta())