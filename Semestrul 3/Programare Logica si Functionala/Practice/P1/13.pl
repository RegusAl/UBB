/*
 a. Sa se scrie un predicat care transforma o lista intr-o multime, in
ordinea ultimei aparitii. Exemplu: [1,2,3,1,2] e transformat in [3,1,2].
 b. Sa se calculeze cel mai mare divizor comun al elementelor unei
 liste.
*/

 % A)

 % nrAparitii(L: lista, E: element, Nr: int)
 % model flux: (i, i, o)

 nrAparitii([], _, 0):-!.
 nrAparitii([H|T], E, Nr):- H == E,
                            !,
                            nrAparitii(T, E, Nr1),
                            Nr is Nr1 + 1.
 nrAparitii([_|T], E, Nr):- nrAparitii(T, E, Nr).


 % multime(L: lista, R: rezultat)
 % model flux: (i, o)

 multime([], []):-!.
 multime([H|T], R):- nrAparitii(T, H, Nr),
                     Nr >= 1,
                     !,
                     multime(T, R).
 multime([H|T], [H|R]):- nrAparitii(T, H, Nr),
                         Nr == 0,
                         multime(T, R).


 % B)

 % cmmdc(A: int, B: int, R: int)
 % model flux: (i,i,o)

 cmmdc(A, B, A):- B is 0, !.
 cmmdc(A, B, R):- E is mod(A, B),
                  cmmdc(B, E, R).

 % calculareCmmdc(L: list, R: int)
 % model flux: (i, o)

 calculareCmmdc([R], R):-!.
 calculareCmmdc([H1|T], R) :- calculareCmmdc(T, R1),
                              cmmdc(H1, R1, R).
