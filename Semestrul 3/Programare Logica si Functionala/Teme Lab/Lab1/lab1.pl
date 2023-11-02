
/* nrAparitiiElement(L: lista, E: element, R: intreg)
 * model flux: (i, i, o)
 * L: lista in care numaram aparitiile elementului E.
 * E: elementul a carui aparitie o numaram.
 * R: numarul de aparitii a elementului E in lista L.
 */

nrAparitiiElement([], _, 0).                                           % daca lista este goala
nrAparitiiElement([H|T], E, R):- H == E,
                                 nrAparitiiElement(T, E, R1),
                                 R is R1 + 1.

nrAparitiiElement([H|T], E, R):- H\=E,
                                 nrAparitiiElement(T, E, R).


/* esteMultime(L: lista)
 * model flux: (i)
 * L: lista ce se verifica daca este multime.
 */


esteMultime([]):- true.
esteMultime([H|T]):- nrAparitiiElement(T,H,R),
                     R > 0,
                     false.

esteMultime([H|T]):- nrAparitiiElement(T,H,R),
                     R = 0,
                     esteMultime(T).


/* eliminareNr(L: lista, E: element, R: lista)
 *  model flux: (i,i,o)
 *  L: lista din care se sterg primele 3 aparitii ale elementului E
 *  (daca exista).
 *  E: elementul ce se sterge din lista.
 *  R: lista rezultata.
 */

eliminareNr(L,E,R):- eliminareNr3(L,E,R,3). % wrapper

/*
 * eliminareNr3(L: lista, E: element, R: rezultat, N: numar)
 * model flux(i,i,o,i)
 */

eliminareNr3([],_,[],_).
eliminareNr3([H|T],E,R,N):- H == E,
                           N > 0,
                           N1 is N-1,
                           !,
                           eliminareNr3(T,E,R,N1).

eliminareNr3([H|T],E,R,N):- eliminareNr3(T,E,R1,N),
                           R = [H|R1].




