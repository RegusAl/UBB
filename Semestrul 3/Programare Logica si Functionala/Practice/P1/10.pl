/*
a. Sa se intercaleze un element pe pozitia a n-a a unei liste.
b. Definiti un predicat care intoarce cel mai mare divizor comun al
numerelor dintr-o lista.
*/

% A)

% interclasare(L: lista, E: element, N: pozitia de inserare, P: pozitia
% actuala, R: lista)
% model flux: (i,i,i,i,o)
interclasare([], E, _, _, [E]).
interclasare([H|T], E ,N,N, [E,H|T]):-!.
interclasare([H|T], E, N, P, [H|R]) :- P < N,!,
                                        P1 is P + 1,
                                        interclasare(T, E, N, P1, R).

interclasare(L, E, N, R):- interclasare(L, E, N, 0, R).


% B)

% cmmdc(A: int, B: int, R: int)
% model flux: (i, i, o)
 cmmdc(A, B, A):- B is 0, !.
 cmmdc(A, B, R):- E is mod(A,B),
                  cmmdc(B, E, R).

 % lista(L: list, R: int)
 % model flux: (i, o)
 lista([E], E):-!.
 lista([H|T], R):- lista(T, R1),
                   cmmdc(H, R1, R).
