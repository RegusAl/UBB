/* a) Sa se sorteze o lista cu eliminarea dublurilor. De ex: [4 2 6 2 3 4] => [2 3 4 6]
*  b) Se da o lista eterogena, formata din numere intregi si liste de
*  numere. Sa se sorteze fiecare sublista fara pastrarea dublurilor. De
*  ex: [1, 2, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, [1, 1, 1], 7] => [1,2, [1, 4], 3, 6, [1, 3, 7, 9, 10], 5, [1], 7].
*/

%  inserare(L: list, X: elem, R: list)
%  model flux: (i, i, o)
inserare([], X, [X]) :- !.
inserare([H|T], X, [H|R]) :- X > H, !, inserare(T, X, R).
inserare([H|T], X, [X,H|T]) :- X < H, !.
inserare(L, _, L).

% sorteaza(L: list, R: list)
% model flux: (i, o)
sorteaza([], []).
sorteaza([H|T], R):- sorteaza(T, R1),
                     inserare(R1, H, R).

% lista(L: list, R: list)
% model flux: (i, o)
lista([], []).
lista([H|T], [R1|R]) :- is_list(H),
                        sorteaza(H, R1),
                        lista(T, R),
                        !.
lista([H|T], [H|R]) :- lista(T, R).












