/*
a. Sa se scrie un predicat care intoarce intersectia a doua multimi.
b. Sa se construiasca lista (m, ..., n), adica multimea numerelor intregi
din intervalul [m, n].
*/

% A)

% nrAparitii(L: lista, E: element, Nr: int)
% model flux (i, i, o)

nrAparitii([], _, 0):-!.
nrAparitii([H|T], E, Nr) :- H == E,
                            !,
                            nrAparitii(T, E, Nr1),
                            Nr is Nr1 + 1.
nrAparitii([_|T], E, Nr) :- nrAparitii(T, E, Nr).


% intersectie(L1: lista, L2: lista, R: lista)
% model flux: (i, i, o)

intersectie([], _, []):-!.
intersectie([H|T], L, [H|R]) :- nrAparitii(L, H, Nr),
                                Nr > 0,
                                !,
                                intersectie(T, L, R).
intersectie([_|T], L, R) :- intersectie(T, L, R).


% B)

% listaInterval(M: int, N: int, E: int, R: lista)

 listaInterval(_, N, N, [N]).
 listaInterval(M, N, E, [E|R]) :- E \= N,
                               !,
                               E1 is E + 1,
                               listaInterval(M, N, E1, R).

 listaInterval(M,N,R):- listaInterval(M,N,M,R).
