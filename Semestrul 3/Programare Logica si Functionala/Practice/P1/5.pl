/*
a. Sa se scrie un predicat care sterge toate aparitiile unui anumit atom
dintr-o lista.
b. Definiti un predicat care, dintr-o lista de atomi, produce o lista de
perechi (atom n), unde atom apare in lista initiala de n ori. De ex:
numar([1, 2, 1, 2, 1, 3, 1], X) va produce X = [[1, 4], [2, 2], [3, 1]].
*/

% A)

% elimina(L: list, X: atom, R: list)
% model flux: (i, i, o)
elimina([], _, []):-!.
elimina([H|T], X, [H|R]) :-  H \= X,
                             !,
                             elimina(T, X, R).
elimina([_|T], X, R) :- elimina(T, X, R).


% B)

% numarare(L: list, X: atom, Nr: int)
% model flux: (i, i, o)
numarare([], _, 0):-!.
numarare([H|T], X, Nr) :- H == X,
                          !,
                          numarare(T, X, Nr1),
                          Nr is Nr1+1.
numarare([_|T], X, Nr) :- numarare(T, X, Nr).


% numar(L: list, R: atom)
% model flux: (i, o)H
numar([], []):-!.
numar([H|T], [L|R]):- numarare([H|T], H, Nr),
                      L = [H,Nr],
                      elimina(T, H, R1),
                      numar(R1, R).






