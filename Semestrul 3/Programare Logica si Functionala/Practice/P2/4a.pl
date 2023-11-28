% Sa se interclaseze fara pastrarea dublurilor doua liste sortate.

% model matematic

% interclasare(x1...xn, z1...zm) = { x1...xn, m = 0
%                                  { z1...zm, n = 0
%                                  { x1 U interclasare(x2...xn,z2...zm),
%                                    daca x1==z1
%                                  { x1 U interclasare(x2...xn,z1...zm),
%                                    daca x1<z1
%                                  { z1 U interclasare(x1...xn,z2...zm),
%                                    daca z1<x1


% intercalsare(L1: lista, L2: lista, R: lista)
% model flux: (i, i, o)

  interclasare(E, [], E):-!.
  interclasare([], E, E):-!.
  interclasare([H1|T1], [H2|T2], [H1|R]):- H1 == H2,
                                           !,
                                           interclasare(T1, T2, R).
  interclasare([H1|T1], [H2|T2], [H1|R]):- H1 < H2,
                                           !,
                                           interclasare(T1, [H2|T2], R).
  interclasare([H1|T1], [H2|T2], [H2|R]):- H1 > H2,
                                           !,
                                           interclasare([H1|T1], T2, R).

