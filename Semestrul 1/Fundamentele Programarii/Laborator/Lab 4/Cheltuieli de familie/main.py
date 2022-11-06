'''
Scrieți o aplicație care gestionează cheltuielile de familie efectuate într-o lună.
Pentru o cheltuială se vor retine ziua (din luna), suma, tipul cheltuielii (5 categorii: mâncare, întreținere, îmbrăcăminte, telefon, altele)

Aplicatia are interfata de tip consola, si ofera urmatoarele functionalitati:

1. Adaugă cheltuiala:
    - Adaugă o noua cheltuiala (se specifica ziua, suma, tipul)
    - Actualizează cheltuiala (se specifica ziua, suma, tipul)
2. Stergere:
    - Șterge toate cheltuielile pentru ziua dată
    - Șterge cheltuielile pentru un interval de timp (se dă ziua de început și sfârșit, se șterg toate cheltuielile pentru perioada dată)
    - Șterge toate cheltuielile de un anumit tip
3. Căutări:
    - Tipărește toate cheltuielile mai mari decât o sumă dată
    - Tipărește toate cheltuielile efectuate înainte de o zi dată și mai mici decât o sumă (se dă suma și ziua, se tipăresc toate cheltuielile mai mici ca suma dată și efectuate înainte de ziua specificată)
    - Tipărește toate cheltuielile de un anumit tip
4. Rapoarte:
    - Tipărește suma totală pentru un anumit tip de cheltuială
    - Găsește ziua în care suma cheltuită e maximă
    - Tipărește toate ch6
    eltuielile ce au o anumită sumă
    - Tipărește cheltuielile sortate după tip
5. Filtrare:
    - Elimină toate cheltuielile de un anumit tip
    - Elimină toate cheltuielile mai mici decât o sumă dată
6. Undo:
    - Reface ultima operație (lista de cheltuieli revine ce exista înainte de ultima operație care a modificat lista)
'''

from ui.console import start

start()

