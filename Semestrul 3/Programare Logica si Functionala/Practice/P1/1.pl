/*
*  a. Sa se scrie un predicat care intoarce diferenta a doua multimi.
*  b. Sa se scrie un predicat care adauga intr-o lista dupa fiecare
*  element par valoarea 1.
*/

% A)

/*
   cautareElement(l1...ln, X) = {  false                      , n = 0
                                {  true                       , X = l1
                                {  cautareElement(l2...ln, X) , altfel
*/

% cautareElement(L: lista, X: elem)
% model flux: (i, i)
cautareElement([], _) :- false,
                         !.
cautareElement([X|_], X) :- true,
                         !.
cautareElement([_|T], X) :- cautareElement(T, X).


/*
 diferenta(l1...ln, m1...mn) = { []                          ,n = 0
                               { diferenta(l2...ln, m1...mn) ,cautareElement(m1...mn, X) = true { l1 +
                               { diferenta(l2...ln, m1...mn)
 */

% diferenta(M1: lista, M2: lista, R: lista)
% model flux: (i, i, o)
diferenta([], _, []) :- !.
diferenta([H|T], M2, R) :-cautareElement(M2, H),
                          !,
                          diferenta(T, M2, R).
diferenta([H|T], M2, R):- diferenta(T, M2, R1),
                          R = [H|R1].

% B)

/*
adaugaDupaPar1(l1...ln) = { []                              , n = 0
                          { l1 + 1 + adaugaDupaPar1(l2...ln), l1 % 2 = 0
                          { l1 + adaugaDupaPar1(l2...ln)    , altfel
 */



% adaugaDupaPar1(L: lista, R: lista)
% model fliux: (i, o) / (i, i)

adaugaDupaPar1([], []).
adaugaDupaPar1([H|T], R) :- 0 is mod(H, 2),
                            !,
                            adaugaDupaPar1(T, R1),
                            R = [H,1|R1].
adaugaDupaPar1([H|T], [H|R]) :- adaugaDupaPar1(T, R).


