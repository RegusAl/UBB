/*
a. Sa se scrie un predicat care elimina dintr-o lista toate elementele care
se repeta (ex: l=[1,2,1,4,1,3,4] => l=[2,3])
b. Sa se elimine toate aparitiile elementului maxim dintr-o lista de numere
intregi.
*/

% A)

% numarareElemente(L: list, E: elem, Nr: int)
% model flux: (i, i, o)
numarareElemente([], _, 0):-!.
numarareElemente([H|T], E, Nr) :- H == E,
                                  !,
                                  numarareElemente(T, E, Nr1),
                                  Nr is Nr1 + 1.
numarareElemente([_|T], E, Nr) :- numarareElemente(T, E, Nr).


% elimina(L: list, X: atom, R: list)
% model flux: (i, i, o)
elimina([], _, []):-!.
elimina([H|T], X, [H|R]) :-  H \= X,
                             !,
                             elimina(T, X, R).
elimina([_|T], X, R) :- elimina(T, X, R).

% eliminareElementeDuplicate(L: list, R: list)
% model flux: (i, o)
eliminareElementeDuplicate([], []):-!.
eliminareElementeDuplicate([H|T], R) :- numarareElemente(T, H, Nr),
                                  Nr > 0,!,
                                  elimina(T, H, R1),
                                  eliminareElementeDuplicate(R1, R).
eliminareElementeDuplicate([H|T], [H|R]) :- eliminareElementeDuplicate(T, R).


% B)


% max(L: lista, X: int)
% model flux: (i, o)
max([X], X):-!.
max([H|T], X):- max(T, X1),
                X is max(H, X1).


% eliminareMax(L: list, R: list)
% model flux: (i, o)
eliminareMax([], []):-!.
eliminareMax(L, R) :- max(L, X),
                      elimina(L, X, R).
