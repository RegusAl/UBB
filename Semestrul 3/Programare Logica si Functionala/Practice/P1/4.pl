/*
 a. Sa se scrie un predicat care substituie intr-o lista un element printr-o
alta lista.
 b. Sa se elimine elementul de pe pozitia a n-a a unei liste liniare.
*/

 % A)

 % substituie(L: list, E: elem, I: list, R: list)
 % model flux: (i, i, i, o)
 substituie([], _, _, []) :- !.
 substituie([H|T], E, I, [I|R]) :- H == E,
                                   !,
                                   substituie(T, E, I, R).
 substituie([H|T], E, I, [H|R]) :- substituie(T, E, I, R).


 % B)

 % eliminare(L: list, N: int, R: list)
 % model flux: (i, i, o)
 eliminare([], _, []) :- !.
 eliminare([H|T], N, [H|R]) :- N \= 0,
                               !,
                               P is N - 1,
                               eliminare(T, P, R).
 eliminare([_|T], N, R) :- P is N - 1,
                           eliminare(T, P, R).

