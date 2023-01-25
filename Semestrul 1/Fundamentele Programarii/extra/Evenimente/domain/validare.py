class Validare:

    def __init__(self):
        pass

    def validare(self, data, ora):
        '''
        Functia ce valideaza data si ora
        :param data: data evenimentului (string)
        :param ora: ora evenimentului (string)
        :return: -
        :raises: ValueError: - daca data nu reprezinta o data valida
                             - daca ora nu reprezinta o ora valida
        '''
        zi, luna, an = data.split(".")
        if int(zi) <= 0 or int(zi) > 31:
            raise ValueError("Data trebuie sa reprezinte o data valida!")
        if int(luna) <= 0 or int(luna) > 12:
            raise ValueError("Data trebuie sa reprezinte o data valida!")
        if int(an) < 0:
            raise ValueError("Data trebuie sa reprezinte o data valida!")
        h, m = ora.split(":")
        if int(h) < 0 or int(h) > 23:
            raise ValueError("Ora trebuie sa reprezinte o ora valida!")
        if int(m) < 0 or int(m) > 59:
            raise ValueError("Ora trebuie sa reprezinte o ora valida!")