% A)
% Sa se sorteze o lista cu eliminarea dublurilor.
% De ex: [4 2 6 2 3 4] => [2 3 4 6]

% inserare(L: list, E: elem, R: list)
% model flux: (i, i, o)
  inserare([], E, [E]):-!.
  inserare([H|T], E, [E,H|T]):- E < H,
                                !.
  inserare([H|T], E, [H|R]) :- E > H,
                               !,
                               inserare(T, E, R).
  inserare(L, _, L).


% sortare(L: list, R: list)
% model flux: (i, o)

 sortare([], []).
 sortare([H|T], R):- sortare(T, R1),
                     inserare(R1, H, R).
