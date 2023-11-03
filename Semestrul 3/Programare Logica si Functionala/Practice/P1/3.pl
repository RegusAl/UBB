/*
 a. Sa se scrie un predicat care transforma o lista intr-o multime, in
ordinea primei aparitii. Exemplu: [1,2,3,1,2] e transformat in [1,2,3].
 b. Sa se scrie o functie care descompune o lista de numere intr-o lista
 de forma [ lista-de-numere-pare lista-de-numere-impare] (deci lista cu
 doua elemente care sunt liste de intregi), si va intoarce si numarul
 elementelor pare si impare.
*/

% A)

% elimina(L: list, E: elem, R: list)
% model flux: (i , i, o)
elimina([], _, []) :- !.
elimina([H|T], E, [H|R]) :- H \= E,
                            !,
                            elimina(T, E, R).
elimina([_|T], E, R) :- elimina(T, E, R).



% creareMultime(L: list, R: list)
% model flux: (i, o)
creareMultime([], []) :- !.
creareMultime([H|T], [H|R]) :- elimina(T, H, R1),
                               creareMultime(R1, R).



% B)

% listaPar(L: list, R: list)
% model flux: (i, o)
listaPar([], []):-!.
listaPar([H|T], [H|R]) :- 0 is mod(H,2),
                          !,
                          listaPar(T, R).
listaPar([_|T], R) :- listaPar(T, R).

% listaImpar(L: list, R: list)
% model flux: (i, o)
listaImpar([], []):-!.
listaImpar([H|T], [H|R]) :- 1 is mod(H,2),
                            !,
                            listaImpar(T, R).
listaImpar([_|T], R) :- listaImpar(T, R).

% lungime(L: list, N: int)
% model flux: (i, o)
lungime([], 0) :- !.
lungime([_|T], N) :- lungime(T, N1),
                     N is N1 + 1.

% listaPareImpare(L: list, R: list, Np: int, Ni: int)
% model flux: (i, o, i, i)
listaPareImpare([], []):-!.
listaPareImpare(L, [Rp,Np,Ri,Ni]) :- listaPar(L, Rp),
                           listaImpar(L, Ri),
                           lungime(Rp, Np),
                           lungime(Ri, Ni).
