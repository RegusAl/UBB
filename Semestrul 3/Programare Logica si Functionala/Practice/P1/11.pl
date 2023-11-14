/*
 a. Sa se scrie un predicat care sa testeze daca o lista formata din
 numere intregi are aspect de "vale"(o multime se spune ca are aspect de
 "vale" daca elementele descresc pana la un moment dat, apoi cresc. De
 ex. 10 8 6 9 11 13).
 b. Sa se calculeze suma alternanta a elementelor
 unei liste (l1 - l2 + l3 ...).
*/

 % A)

 % vale(L: lista, UP: int, DOWN: int)
 % model flux: (i, i)

 vale([_], UP, DOWN):- vale(UP, DOWN).
 vale([H1,H2|T], UP, DOWN):-
                             H1 < H2,
                             !,
                             DOWN1 is DOWN + 1,
                             vale([H2|T], UP, DOWN1).
 vale([H1,H2|T], UP, DOWN):-
                             H1 > H2,
                             DOWN =< 0,
                             !,
                             UP1 is UP + 1,
                             vale([H2|T], UP1, DOWN).

 vale(UP, DOWN):- UP > 0,
                  DOWN > 0,!.

 vale(L) :- vale(L, 0, 0).

 % B)

 % sumaAlternanta(L: lista, ok: int, S: int)
 % model flux: (i, i, o)
 sumaAlternanta([], _, 0).
 sumaAlternanta([H|T], Ok, S) :- Ok == 0,
                                 !,
                                 Ok1 is Ok + 1,
                                 sumaAlternanta(T, Ok1, S1),
                                 S is S1 + H.
 sumaAlternanta([H|T], Ok, S) :- Ok == 1,
                                 !,
                                 Ok1 is Ok - 1,
                                 sumaAlternanta(T, Ok1, S1),
                                 S is S1 - H.

 sumaAlternanta(L, S):- sumaAlternanta(L, 0, S).





