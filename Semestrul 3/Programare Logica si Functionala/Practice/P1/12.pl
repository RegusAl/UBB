/*
 a. Sa se scrie un predicat care substituie intr-o lista un element prin
altul.
 b. Sa se construiasca sublista (lm, ..., ln) a listei (l1, ..., lk).
*/

 % A)

 % substituie(L: list, E: elem, X: elem, R: list)
 % model flux: (i,i,i,o)

 substituie([], _, _, []).
 substituie([H|T], E, X, [X|R]):- H == E,
                                  !,
                                  substituie(T, E, X, R).
 substituie([H|T], E, X, [H|R]):- substituie(T, E, X, R).


 % B)

 % sublista(L: list, P: int, M: int, N: int, R: list)
 % model flux: (i,i,i,o)

 sublista([], _, _, _,[]):-!.
 sublista([H|T], P, M, N, [H|R]):- P >= M,
                                   P =< N,
                                   !,
                                   P1 is P + 1,
                                   sublista(T, P1, M, N, R).
 sublista([_|T], P, M, N, R) :- P1 is P + 1,
                                sublista(T, P1, M, N, R).

 sublista(L, M, N, R):- sublista(L, 0, M, N, R).
