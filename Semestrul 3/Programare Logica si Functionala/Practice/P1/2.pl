/*
 a. Sa se scrie un predicat care determina cel mai mic multiplu comun al
 elementelor unei liste formate din numere intregi.
 b. Sa se scrie un predicat care adauga dupa 1-ul, al 2-lea, al 4-lea,
 al 8-lea ...element al unei liste o valoare v data.
*/

% A)

% cmmc(A: int, B: int, R: int)
% model flux: (i, i, o)
cmmdc(0, B, R) :- !, R = B.
cmmdc(A, 0, R) :- !, R = A.
cmmdc(A, B, R) :- A > B,
                  !,
                  C is A mod B,
                  cmmdc(C, B, R).
cmmdc(A, B, R) :- A < B,
                  !,
                  C is B mod A,
                  cmmdc(A, C, R).

% wraper
% lista_cmmc(L: lista, R: lista)
% model flux: (i, o)
lista_cmmmc(L, R):- lista_cmmmc(L, 1, R).

% lista_cmmmc(L: lista, C: int, R: int)
% model flux: (i, i, o)
lista_cmmmc([], C, R) :- !, R is  C.
lista_cmmmc([H|T], C, R) :- cmmdc(C, H, R1),
                            A is C * H,
                            B is A / R1,
                            lista_cmmmc(T, B, R).


% B)

% inserareV(L: list, Poz: int, Contor: int, V: elem, R: list)
% model flux: (i, i, i, i, o)
inserareV([], _, _, _, []).
inserareV([H|T], Poz, Contor, V, [H,V|R1]) :- Contor =:= Poz,
                                       !,
                                       Poz1 is Poz + 1,
                                       Contor1 is Contor * 2,
                                       inserareV([H|T], Poz1, Contor1, V, R1).
inserareV([H|T], Poz, Contor, V, [H|R1]) :- Poz1 is Poz + 1,
                                      inserareV(T, Poz1, Contor, V, R1).

% wrapper
% inserareV(L: list, V: elem, R: list)
% model flux: (i, i, o)
inserareV(L, V, R) :- inserareV(L, 1, 1, V, R).


