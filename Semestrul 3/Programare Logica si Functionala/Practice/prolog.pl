% numar aparitie element
nrAparitieElement([], _, 0).
nrAparitieElement([H|T], E, R):- H == E,
                                 !,
                                 nrAparitieElement(T, E, R1),
                                 R is R1 + 1.
nrAparitieElement([_|T], E, R):- nrAparitieElement(T, E, R).


% numar elemente
nrElemente([], 0).
nrElemente([_|T], R):- nrElemente(T, R1),
                       R is R1 + 1.

% eliminare elemente ce se repeta
eliminareRepetitii([], []).
eliminareRepetitii([H|T], R):- nrAparitieElement(T, H, Nr),
                               Nr > 0,
                               !,
                               eliminareRepetitii(T, R).
eliminareRepetitii([H|T], [H|R]):- eliminareRepetitii(T, R).


% sortare elemente
inserareElement([], E, [E]):-!.
inserareElement([H|T], E, [E,H|T]):- E =< H,
                                     !.
inserareElement([H|T], E, [H|R]):- E > H,
                                   !,
                                   inserareElement(T, E, R).
inserareElement(L, _, L).


sortare([], []).
sortare([H|T], R):- sortare(T, R1),
                    inserareElement(R1, H, R).


% cel mai mare divizor comun
cmmdc(0, B, B):-!.
cmmdc(A, 0, A):-!.
cmmdc(A, B, R):- A > B,
                 !,
                 C is A mod B,
                 cmmdc(C, B, R).
cmmdc(A, B, R):- A < B,
                 !,
                 C is B mod A,
                 cmmdc(A, C, R).

% cel mai mic multiplu comun
% cmmmc(a, b) = (a * b) / cmmdc(a, b)
lista_cmmmc([], C, R):-!, R is C.
lista_cmmmc([H|T], C, R):- cmmdc(C, H, R1),
                           A is C * H,
                           B is A / R1,
                           lista_cmmmc(T, B, R).

% pozitia elementului
poz([], _, _, _):-!, false.
poz([H|_], I, E, I):- H == E,
                      !.
poz([_|T], I, E, R):- I1 is I + 1,
                      poz(T, I1, E, R).

poz(L, E, R):- poz(L, 1, E, R).


% eliminare n elemente de acelasi fel
eliminareN([], _, _, []):-!.
eliminareN([H|T], N, H, R):- N > 0,
                             !,
                             N1 is N - 1,
                             eliminareN(T, N1, H, R).
eliminareN([H|T], N, E, [H|R]):- eliminareN(T, N, E, R).

% maximul din lista
max([E], E):-!.
max([H1,H2|T], R):- H1 =< H2,
                    !,
                    max([H2|T], R).
max([H1,H2|T], R):- H1 > H2,
                    max([H1|T], R).

% multimea tuturor perechilor din lista
perechi([], _, []):-!.
perechi([H|T], E, [[E,H]|R]):- perechi(T, E, R).

lista_perechi([], []):-!.
lista_perechi([H|T], [R1|R]):- perechi(T, H, R1),
                               lista_perechi(T, R).

