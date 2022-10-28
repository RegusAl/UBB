from utils.operations import adauga_cheltuiala, stergere_cheltuiala_zi, stergere_cheltuiala_tip, \
    stergere_cheltuiala_interval, creeaza_cheltuiala

# Lista cu cheltuieli
def global_list():
    return [{"zi":  1, "suma": 25, "tip": "mancare"},
            {"zi":  4, "suma": 45, "tip": "intretinere"},
            {"zi":  7, "suma": 29.16, "tip": "telefon"},
            {"zi":  12, "suma": 99.78, "tip": "imbracaminte"},
            {"zi":  15, "suma": 100.78, "tip": "mancare"},
            {"zi":  20, "suma": 13.90, "tip": "altele"},
            {"zi": 21, "suma": 14.789, "tip": "intretinere"},
            {"zi": 23, "suma": 200.90, "tip": "imbracaminte"},
            {"zi": 30, "suma": 123.456, "tip": "altele"}
            ]

# functii

def get_zi(cheltuiala):
    return cheltuiala['zi']

def get_suma(cheltuiala):
    return cheltuiala['suma']

def get_tip(cheltuiala):
    return cheltuiala['tip']

# Validari

## testare pentru cazurile cu exceptie la adaugare cheltuiala
def test_cheltuiala_valida(cheltuiala):
    tip = ["mancare", "intretinere", "imbracaminte", "telefon", "altele"]
    assert (type(cheltuiala) == dict)
    assert (type(get_suma(cheltuiala)) == float)
    assert (type(get_zi(cheltuiala)) == int)
    assert (get_zi(cheltuiala)>0 and get_zi(cheltuiala)<=31)
    assert (get_tip(cheltuiala) in tip)

## testare pentru cazurile cu exceptie la zi
def test_zi_valida(zi):
    assert (zi > 0 and zi <= 31)
    assert (type(zi)==int)

## testare pentru cazurile de exceptie la suma
def test_suma_valida(suma):
    assert (suma > 0)
    assert (type(suma)==float)

## testare pentru cazurile cu exceptie la tipul de cheltuiala
def test_tip_valid(tip):
    tipuri_cheltuieli = ["mancare", "intretinere", "imbracaminte", "telefon", "altele"]
    assert(tip in tipuri_cheltuieli)

# Teste

def test_adaugare_cheltuiala():
    cheltuiala1 = creeaza_cheltuiala(13, 200.987, "mancare")
    assert (type(cheltuiala1)==dict)
    assert (get_zi(cheltuiala1)==13)
    assert (get_suma(cheltuiala1)==200.987)
    assert (get_tip(cheltuiala1)=="mancare")
    lista = []
    adauga_cheltuiala(lista, cheltuiala1)
    assert (type(lista) == list)

def test_stergere_cheltuiala():
    lista = global_list()
    assert (len(lista)==9)
    stergere_cheltuiala_zi(lista, 7)
    assert (len(lista)==8)
    stergere_cheltuiala_tip(lista, "mancare")
    assert (len(lista)==6)
    stergere_cheltuiala_interval(lista, 1, 31)
    assert (len(lista)==0)

test_adaugare_cheltuiala()
test_stergere_cheltuiala()