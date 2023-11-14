/*
a. Sa se scrie un predicat care testeaza daca o lista este multime.
b. Sa se scrie un predicat care elimina primele 3 aparitii ale unui element
intr-o lista. Daca elementul apare mai putin de 3 ori, se va elimina de
cate ori apare.
*/

% A)

% nrAparitii(L: lista, E: element, Nr: int)
% model flux (i, i, o)

nrAparitii([], _, 0):-!.
nrAparitii([H|T], E, Nr) :- H == E,
                            !,
                            nrAparitii(T, E, Nr1),
                            Nr is Nr1 + 1.
nrAparitii([_|T], E, Nr) :- nrAparitii(T, E, Nr).

% esteMultime(L: lista)
% model flux (i)

esteMultime([]):-true.
esteMultime([H|T]) :- nrAparitii(T, H, Nr),
                      Nr >= 1,!,
                      false.
esteMultime([_|T]):- esteMultime(T).

% B)

% eliminaElement(L: lista, E: element, R: lista, Nr: int)
% model flux: (i, i, o)

eliminaElement([], _, [], _).
eliminaElement([H|T], E, R, Nr):- H == E,
                                  Nr > 0,
                                  Nr1 is Nr - 1,
                                  !,
                                  eliminaElement(T, E, R, Nr1).
eliminaElement([H|T], E, [H|R], Nr) :- eliminaElement(T, E, R, Nr).

elimina3Element(L, E, R) :- eliminaElement(L, E, R, 3).
