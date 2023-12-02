/*
 Se da sirul a1,..., an format din numere intregi distincte. Se cere sa se
afiseze toate submultimile cu aspect de "munte"(o secvență se spune ca are
aspect de "munte" daca elementele cresc pana la un moment dat, apoi descresc. De
ex. 10 16 27 18 14 7).
*/



% candidat(l1...ln) =  1) l1, n > 0
%                      2) candidat(l2...ln), n > 0

% candidat(L: list, E: int) - genereaza un candidat la solutie
% model flux: (i, o) - predicat nedeterminist
candidat([H|_], H).
candidat([_|T], E):- candidat(T, E).

% generare(l, c1...cn, f) = 1) c1...cn, f = 0
%                           2) generare(l, ec1...cn, 1), f = 1, e > c1
%                              unde e = candidat(l)
%                           3) generare(l, ec1...cn, 0), f = 0, e < c1
%                              unde e = candidat(l) si nu exista
%                              candidat(c1...cn) = e

% generare(L: list, C: list, F: int, R: list)
% model flux: (i, i, i, o) - predicat nedeterminist
generare(_, C, 0, C).
generare(L, [H|T], 1, R):- candidat(L, E),
                           E > H,
                           generare(L, [E|[H|T]], 1, R).
generare(L, [H|T], _, R):- candidat(L, E),
                           not(candidat([H|T], E)),
                           E < H,
                           generare(L, [E|[H|T]], 0, R).


% generareMain(l) = generare(l, [l1,l2], 1) unde l1 = candidat(l),
%                                                l2 = candidat(l),
%                                                l1 > l2

% generareMain(L: list, R: list)
% model flux: (i, o) - predicat nedeterminist
generareMain(L, R):- candidat(L, E1),
                     candidat(L, E2),
                     E1 > E2,
                     generare(L, [E1, E2], 1, R).

% main(l) = U generareMain(l)

% main(L: list, R: list)
% model flux: (i, o)
main(L, R):- findall(R1, generareMain(L, R1), R).
