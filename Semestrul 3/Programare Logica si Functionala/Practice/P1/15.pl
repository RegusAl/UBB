/*
 a. Sa se scrie un predicat care se va satisface daca o lista are numar
par de elemente si va esua in caz contrar, fara sa se numere elementele
listei.
 b. Sa se elimine prima aparitie a elementului minim dintr-o lista de
 numere intregi.
*/

 % A)

 % paritare(L: list, Ok: int)
 % model flux: (i, i)

 paritate([], 0):-true.
 paritate([_|T], Ok):- Ok == 0,
                       !,
                       Ok1 is Ok + 1,
                       paritate(T, Ok1).
 paritate([_|T], Ok):- Ok == 1,
                       Ok1 is Ok - 1,
                       paritate(T, Ok1).

 paritate(L) :- paritate(L, 0).


 % B)

 % minim(L: lista, M: minim)
 % model flux: (i, i) || (i, o)

 minim([E], E):-!.
 minim([H|T], M) :- minim(T, MTail),
                    H < MTail,
                    !,
                    M is H.
 minim([_|T], M) :- minim(T, MTail),
                  M is MTail.


 % eliminareMinim(L: lista, R: lista)
 % model flux: (i, o)

 eliminareMinim([], [], _).
 eliminareMinim([H|T], R, Ok):- Ok == 0,
                                minim([H|T], M),
                                H == M,
                                !,
                                Ok1 is Ok + 1,
                                eliminareMinim(T, R, Ok1).
 eliminareMinim([H|T], [H|R], Ok):- eliminareMinim(T, R, Ok).

 eliminareMinim(L, R):- eliminareMinim(L, R, 0).
