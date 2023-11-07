/* a) Sa se sorteze o lista cu eliminarea dublurilor. De ex: [4 2 6 2 3 4] => [2 3 4 6]
*  b) Se da o lista eterogena, formata din numere intregi si liste de
*  numere. Sa se sorteze fiecare sublista fara pastrarea dublurilor. De
*  ex: [1, 2, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] => [1,2, [1, 4], 3, 6, [1, 3, 7, 9, 10], 5, [1], 7].
*/



%  inserareCrescator(l1...ln, e)= { e, n = 0
%                                 { l1 + inserareCrescator(l2...ln, e),e > l1
%                                 { e + l1 + ... + ln, e < l1
%                                 { l1...ln, altfel

%  inserare(L: list, X: elem, R: list)
%  model flux: (i, i, o)
%  L: lista in care se insereaza elementul E
%  E: elementul ce se insereaza in L daca acesta nu exista
%  R: lista rezultata
inserareCrescator([], X, [X]) :- !.
inserareCrescator([H|T], X, [H|R]) :- X > H, !, inserareCrescator(T, X, R).
inserareCrescator([H|T], X, [X,H|T]) :- X < H, !.
inserareCrescator(L, _, L).

% sorteaza(l1...ln)= { [ ], n = 0
%                    { inserareCrescator(sorteaza(l2...ln), l1), altfel

% sorteaza(L: list, R: list)
% model flux: (i, o)
% L: lista ce se sorteaza
% R: lista sortata
sorteaza([], []).
sorteaza([H|T], R):- sorteaza(T, R1),
                     inserareCrescator(R1, H, R).

% lista(l1...ln) = { [ ], n = 0
%                  { sorteaza(l1) U lista(l2...ln), l1 este lista
%                  { l1 + lista(l2...ln), altfel

% lista(L: list, R: list)
% model flux: (i, o)
% L: lista initiala
% R: lista rezultata
lista([], []).
lista([H|T], [R1|R]) :- is_list(H),
                        sorteaza(H, R1),
                        lista(T, R),
                        !.
lista([H|T], [H|R]) :- lista(T, R).










