% Sa se determine pozitiile elementului maxim dintr-o lista liniara.
% De ex: poz([10,14,12,13,14], L) va produce L = [2,5].


% max(l1...ln) = { l1, n = 1
%                { max(l1,l3...ln), l1 > l2
%                { max(l2...ln), l1 < l2

% max(L: list, M: int)
% model flux: (i, o)
  max([E], E):-!.
  max([H1,H2|T], E):- H1 >= H2,
                      !,
                      max([H1|T], E).
  max([H1,H2|T], E):- H1 < H2,
                      max([H2|T], E).


% poz_max(l1...ln, m, i) = { [], n = 0
%                          { l1 U poz_max(l2...ln, m, i+1), l1 == m
%                          { poz_max(l2...ln, m, i+1), l1 != m

% poz_max(L: list, M: int, I: int, R: list)
% model flux: (i, i, i, o)
  poz_max([], _, _, []):-!.
  poz_max([H|T], M, I, [I|R]):- H == M,
                            !,
                            I1 is I + 1,
                            poz_max(T, M, I1, R).
  poz_max([H|T], M, I, R):- H \= M,
                        I1 is I + 1,
                        poz_max(T, M, I1, R).


% main(l1...ln) = { [], n = 0
%                 { l1 U poz_max(l2...ln, M, I), daca l1 = max(l1...ln)

% main(L: list, R: list)
% model flux: (i, o)
  poz([], []):-!.
  poz(L, R):-  max(L, M),
               poz_max(L, M, 1, R).
