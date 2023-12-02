% Sa se elimine toate secventele crescatoare de minim 2 elemente.
% Ex: [1,2,4,6,7,8,10] => [4, 10]

% stergereCons(l1...ln, ok) = { [], n = 0
%                             { l1, n = 1 si ok = 0
%                             { [], n = 1 si ok = 1
%                             { l1 U stergereCons(l2...ln),
%                             daca l1 != l2-1 si ok = 0
%                             { stergereCons(l2...ln),
%                             daca l1 = l2 - 1 si ok = 1
%                             { stergere(l2...ln),
%                             daca l1 si l2 sunt crescatoare si ok = 0
%                             { stergere(l2...ln),
%                             daca l1 si l2 nu sunt crescatoare si ok=1
%
%
stergereCons([], [], _):-!.
stergereCons([E], [E], 0):-!.
stergereCons([_], [], 1):-!.
stergereCons([H1,H2|T], [H1|R], 0):- not(crescatoare(H1, H2)),!,
                                     stergereCons([H2|T], R, 0).
stergereCons([H1,H2|T], R, 1):- crescatoare(H1,H2),!,
                                stergereCons([H2|T], R, 1).
stergereCons([H1,H2|T], R, 0):- crescatoare(H1, H2),!,
                                stergereCons([H2|T], R, 1).
stergereCons([H1,H2|T], R, 1):- not(crescatoare(H1, H2)),!,
                                stergereCons([H2|T], R, 0).


% wrapper
% stergereCons(L: list, R: list)
% model flux: (i, o)
% stergereCons(l1...ln) = { stergereCons(l1...ln, 0)
stergereCons(L, R):- stergereCons(L, R, 0).


% crescatoare(e1, e2) = { true, e1 < e2
%                       { false, e1 > e2

% crescatoare(H1: int, H2: int)
% model flux: (i, i)
crescatoare(H1, H2):-  R is H2 - 1,
                       H1 == R,!,
                       true.
crescatoare(H1,H2):- H1 \= H2-1, false.

