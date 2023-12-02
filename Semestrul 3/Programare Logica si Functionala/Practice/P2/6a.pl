% Intr-o lista L sa se inlocuiasca toate aparitiile unui element E cu
% elementele unei alte liste, L1.
% De ex: inloc([1,2,1,3,1,4],1,[10,11],X) va produceX=[10,11,2,10,11,3,10,11,4].



% elem(L1: list, L2: list, E: list)
% model flux: (i, o)
  elem([], L, L).
  elem([H|T], L, [H|R]):- elem(T, L, R).

% inloc(L: list, E: element, X: list, R: list)
% model flux: (i, i, i, o)
  inloc([], _, _, []):-!.
  inloc([H|T], E, X, R):- H == E,
                              !,
                              inloc(T, E, X, R1),
                              elem(X, R1, R).
  inloc([H|T], E, X, [H|R]):- inloc(T, E, X, R).
