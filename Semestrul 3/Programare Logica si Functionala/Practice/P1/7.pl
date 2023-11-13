/*
a. Sa se scrie un predicat care intoarce reuniunea a doua multimi.
b. Sa se scrie un predicat care, primind o lista, intoarce multimea
tuturor perechilor din lista. De ex, cu [a, b, c, d] va produce
[[a, b], [a, c], [a, d], [b, c], [b, d], [c, d]].
*/

% A)

% nrAparitiiElement(L: lista, E: element, Nr: int)
% model flux: (i, i, o)
  nrAparitiiElement([],_,0):-!.
  nrAparitiiElement([H|T], E, Nr) :- H == E,
                                     !,
                                     nrAparitiiElement(T, E, Nr1),
                                     Nr is Nr1 + 1.
  nrAparitiiElement([_|T], E, Nr) :- nrAparitiiElement(T, E, Nr).

% reuniune(L1: lista, L2: lista, R: lista)
% model flux: (i, i, o)
  reuniune([], L, L) :-!.
  reuniune([H|T], L, R) :- nrAparitiiElement(L, H, Nr),
                           Nr \= 0,!,
                           reuniune(T, L, R).
  reuniune([H|T], L, [H|R]) :- reuniune(T,L,R).

% B)

% perechi(L: lista, E: element, R: lista)
% model flux: (i, i, o)
  perechi([],_,[]):-!.
  perechi([H|T], E, [[E, H]|R]):- perechi(T, E, R).

% multimePerechi(L: lista, R: lista)
% model flux: (i, o)
  multimePerechi([], []).
  multimePerechi([H|T], [R1|R]) :- perechi(T, H, R1),
                                   multimePerechi(T, R).
