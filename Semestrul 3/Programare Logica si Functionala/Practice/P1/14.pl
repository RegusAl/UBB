/*
 a. Sa se scrie un predicat care testeaza egalitatea a doua multimi,
 fara sa se faca apel la diferenta a doua multimi.
 b. Definiti un predicat care selecteaza al n-lea element al unei liste.
*/

 % A)

 % egalitateMultimi(M1 : lista, M2: lista)
 % model flux: (i, i)

 egalitateMultimi([E], [E]):-!,true.
 egalitateMultimi([H1|_], [H2|_]):- H1 \= H2,
                                    !,
                                    false.
 egalitateMultimi([_|T1], [_|T2]) :- egalitateMultimi(T1, T2).


 % B)

 % selectareNElement(L: lista, P: int, N: int, E: element)
 % model flux: (i,i,i,o)

 selectareNElement([], _, _ , _, _):-!.
 selectareNElement([H|_], P, N, H) :- P == N,!.
 selectareNElement([_|T], P, N, E) :- P1 is P + 1,
                                      selectareNElement(T, P1, N, E).

 selectareElement(L, N, E):- selectareNElement(L, 0, N, E).
