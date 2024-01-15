% 1) Lista aranjamentelor cu nr. par de elemente avand suma numar impar
%  ex: L = [2, 3, 4] => [[2,3],[3,2],[3,4],[4,3]]


% candidat1(l1...ln) = { 1. l1
%                      { 2. candidat(l2...ln)
%
% candidat1(L: list, E: element)
% model flux: (i, o)
candidat1([E|_], E).
candidat1([_|T], E):- candidat1(T, E).


% apare(l1...ln, e) = { false, n = 0
%                     { true, l1 = e
%                     { apare(l2...ln, e), altfel
%
% apare(L: list, E: element)
% model flux: (i, i)
apare([], _):- false.
apare([H|_], E):- H = E, true.
apare([_|T], E):- apare(T, E).


% aranjSum(l) = { aranjAux(l, e, 1, [e]), unde e = candidat(l)
%
% aranjSum(L: list, C: list)
% model flux: (i, o)
aranjSum(L, C):- candidat1(L, E),
                 aranjAux(L, E, 1, [E], C).


% aranjAux(l, sum, len, r) = { r, sum % 2 = 1 si len % 2 = 0
%                            { aranjAux(l, sum + e, len + 1, e U r),
%                              unde e = candidat1(l) si !apare(r, e)
%
% aranjAux(L: list, Sum: int, Len: int, C: list, R: list)
% model flux: (i, i, i, o, o)
aranjAux(_, Sum, Len, C, C):- Sum mod 2 =:= 1, Len mod 2 =:= 0.
aranjAux(L, Sum, Len, [H|T], R):- candidat1(L, E),
                                  not(apare([H|T], E)),
                                  Sum1 is Sum + E,
                                  Len1 is Len + 1,
                                  aranjAux(L, Sum1, Len1, [E|[H|T]], R).


listaAranj(L, R):- findall(C, aranjSum(L, C), R).


% 2) Lista permutarilor multimii 1..N, cu proprietatea ca valoarea absoluta a diferentei intre 2 valori consecutive din permutare este >= 2
% ex: N = 4 => [[3,1,4,2],[2,4,1,3]]

% candidat2(n) = { n, n >=1
%
% candidat2(N: int, R: int)
% model flux: (i, o)
candidat2(N, N).
candidat2(N, R):- N > 1,
                  N1 is N - 1,
                  candidat2(N1, R).


% permutari(n) = { permAux(n, 1, e), unde e = candidat2(n)
%
% permutari(N: int, R: list)
% model flux: (i, o)
permutari(N, R):- candidat2(N, E),
                  permAux(N, 1, [E], R).

 
% permAux(n, len, l1...ln) = { l1...ln, n = len
%                            { permAux(n, len + 1, e U l1...ln), daca
%                            !apare(l1...ln, e) si abs(l1-e) >= 2
%
% permAux(N: int, Len: int, C: list, R: list)
% model flux: (i, i, o, o)
permAux(N, N, R, R).
permAux(N, Len, [H|T], R):- candidat2(N, E),
                            not(apare([H|T], E)),
                            abs(H-E) >= 2,
                            Len1 is Len + 1,
                            permAux(N, Len1, [E|[H|T]], R).

listaPermutari(N, R):- findall(C, permutari(N, C), R).


% 3) Lista aranjamentelor de k elemente dintr-o lista de numere intregi
% pentru care produsul elementelor e mai mic decat o valoare V data.
% ex: L = [1,2,3], k = 2, V = 7 => [[1,2],[2,1],[1,3],[3,1],[2,3],[3,2]]


% aranjKV(l, k, v) = { aranjKVAux(l, k, v, 1, e, [e]), unde e =
%                      candidat1(l) si e < v
%
% aranjKV(L: list, K: int, V: int, R: list)
% model flux: (i, i, i, o)
aranjKV(L, K, V, R):- candidat1(L, E),
                      E < V,
                      aranjKVAux(L, K, V, 1, E, [E], R).


% aranjKVAux(l, k, v, len, prod, c1...cn) = { r = c1...cn, len = k si
%                                             prod < v
%                                           { aranjKVAux(l, k, v,
%                                           len+1, prod * e, e U
%                                           c1...cn), daca len < k si
%                                           e nu apare in c1...cn
%
% aranjKVAux(L: list, K: int, V: int, Len: int, Prod: int, C: list, R:
% list)
% model flux: (i,i,i,i,i,o,o)
aranjKVAux(_, K, V, K, Prod, C, C):- Prod < V.
aranjKVAux(L, K, V, Len, Prod, [H|T], R):- Len < K,
                                           candidat1(L, E),
                                           not(apare([H|T], E)),
                                           Prod1 is Prod * E,
                                           Len1 is Len + 1,
                                           aranjKVAux(L, K, V, Len1, Prod1, [E|[H|T]], R).

main3(L, K, V, R):- findall(C, aranjKV(L, K, V, C), R).



% 4) lista submulţimilor formate cu elemente unei liste listă de numere întregi,
%  având număr suma elementelor număr impar și număr par nenul de
%  elemente pare.
%  ex: [2,3,4] ⇒ [[2,3,4]]

sub3(L, R):- candidat1(L, E),
             E mod 2 =:= 0,
             sub3Aux(L, 1, E, [E], R).
sub3(L, R):- candidat1(L, E),
             E mod 2 =:= 1,
             sub3Aux(L, 0, E, [E], R).


sub3Aux(_, P, Sum, R, R):- Sum mod 2 =:= 1,
                           P > 0,
                           P mod 2 =:= 0.
sub3Aux(L, P, Sum, [H|T], R):- candidat1(L, E),
                               not(apare([H|T], E)),
                               E < H,
                               E mod 2 =:= 0,
                               Sum1 is Sum + E,
                               P1 is P + 1,
                               sub3Aux(L, P1, Sum1, [E|[H|T]], R).
sub3Aux(L, P, Sum, [H|T], R):- candidat1(L, E),
                               not(apare([H|T], E)),
                               E < H,
                               E mod 2 =:= 1,
                               Sum1 is Sum + E,
                               sub3Aux(L, P, Sum1, [E|[H|T]], R).

main4(L, R):- findall(C, sub3(L, C), R).



% 5) lista submulţimilor de sumă S dată, cu elementele unei liste, astfel încât
% numărul elementelor pare din submulțime să fie par
% ex: [1, 2, 3, 4, 5, 6, 10] şi S=10 => [[1,2,3,4], [4,6]]

submultimiSuma(L, S, R):- candidat1(L, E),
                          E =< S,
                          E mod 2 =:= 0,
                          submultimiSumaAux(L, 1, S, E, [E], R).
submultimiSuma(L, S, R):- candidat1(L, E),
                          E =< S,
                          E mod 2 =:= 1,
                          submultimiSumaAux(L, 0, S, E, [E], R).


submultimiSumaAux(_, P, S, S, R, R):- P mod 2 =:= 0.
submultimiSumaAux(L, P, S, Sum, [H|T], R):- candidat1(L, E),
                                            not(apare([H|T], E)),
                                            E < H,
                                            E mod 2 =:= 0,
                                            Sum1 is Sum + E,
                                            P1 is P + 1,
                                            submultimiSumaAux(L, P1, S, Sum1, [E|[H|T]], R).
submultimiSumaAux(L, P, S, Sum, [H|T], R):- candidat1(L, E),
                                            not(apare([H|T], E)),
                                            E < H,
                                            E mod 2 =:= 1,
                                            Sum1 is Sum + E,
                                            submultimiSumaAux(L, P, S, Sum1, [E|[H|T]], R).

main5(L, S, R):- findall(C, submultimiSuma(L, S, C), R).



% 6) generează lista submulţimilor cu suma număr impar, cu valori din intervalul [a, b]
% ex: pentru a=2 și b=4 => [[2,3],[3,4],[2,3,4]]


lista6(A, B, []):- A > B,!.
lista6(A, B, [A|R]):- A1 is A + 1,
                         lista6(A1, B, R).

subSumaImpara(L, R):- candidat1(L, E),
                      subSumaImparaAux(L, E, [E], R).

subSumaImparaAux(_, Sum, R, R):- Sum mod 2 =:= 1.
subSumaImparaAux(L, Sum, [H|T], R):- candidat1(L, E),
                                     not(apare([H|T], E)),
                                     E < H,
                                     Sum1 is Sum + E,
                                     subSumaImparaAux(L, Sum1, [E|[H|T]], R).

main6(A, B, R):- lista6(A, B, L), findall(C, subSumaImpara(L, C), R).



% 7) generează lista combinărilor de k elemente cu numere de la 1 la N, având diferența
% între două numere consecutive din combinare număr par
% ex: N=4, k=2 ⇒ [[1,3],[2,4]]


combinariKelemente(N, K, R):- candidat2(N, E),
                              combinariKelementeAux(N, K, 1, [E], R).

combinariKelementeAux(_, K, K, R, R).
combinariKelementeAux(N, K, Len, [H|T], R):- candidat2(N, E),
                                             E < H,
                                             abs(H-E) mod 2 =:= 0,
                                             Len1 is Len + 1,
                                             combinariKelementeAux(N, K, Len1, [E|[H|T]], R).

main7(N, K, R):- findall(C, combinariKelemente(N, K, C), R).




% 8) lista submulţimilor cu număr par de elemente
% ex: L=[2,3,4] => [[],[2,3],[2,4],[3,4]]

submultimiNrPar(_, []).
submultimiNrPar(L, R):- candidat1(L, E),
                        submultimiNrParAux(L, 1, [E], R).

submultimiNrParAux(_, Len, R, R):- Len mod 2 =:= 0.
submultimiNrParAux(L, Len, [H|T], R):- candidat1(L, E),
                                       E < H,
                                       Len1 = Len + 1,
                                       submultimiNrParAux(L, Len1, [E|[H|T]], R).

main8(L, R):- findall(C, submultimiNrPar(L, C), R).

% 9) lista submulţimilor cu cel puţin N elemente având suma divizibilă
% cu 3.
% ex: L=[2,3,4] și N=1 => [[3],[2,4],[2,3,4]]

submultimiNDiv3(L, N, R):- candidat1(L, E),
                           submultimiNDiv3Aux(L, N, 1, E, [E], R).

submultimiNDiv3Aux(_, N, Len, Sum, R, R):- Len >= N, Sum mod 3 =:= 0.
submultimiNDiv3Aux(L, N, Len, Sum, [H|T], R):- candidat1(L, E),
                                               E < H,
                                               Sum1 is Sum + E,
                                               Len1 is Len + 1,
                                               submultimiNDiv3Aux(L, N, Len1, Sum1, [E|[H|T]], R).

main9(L, N, R):- findall(C, submultimiNDiv3(L, N, C), R).


% 10) lista combinărilor de k elemente dintr-o listă de numere întregi, având
% suma număr par.
% ex: [6, 5, 3, 4], k=2 => [[6,4],[5,3]]

combinariKElemSumPara(L, K, R):- candidat1(L, E),
                                 combinariKElemSumParaAux(L, K, 1, E, [E], R).

combinariKElemSumParaAux(_, K, K, Sum, R, R):- Sum mod 2 =:= 0.
combinariKElemSumParaAux(L, K, Len, Sum, [H|T], R):- candidat1(L, E),
                                                     E > H,
                                                     Sum1 is Sum + E,
                                                     Len1 is Len + 1,
                                                     combinariKElemSumParaAux(L, K, Len1, Sum1, [E|[H|T]], R).

main10(L, K, R):- findall(C, combinariKElemSumPara(L, K, C), R).


% 11) lista submulţimilor cu k elemente în progresie aritmetică
% ex: L=[1,5,2,9,3] şi k=3 => [[1,2,3],[1,5,9],[1,3,5]]

submultimiKelemProg(L, K, R):- candidat1(L, E),
                               subKelemProgAux(L, K, 1, [E], R).

subKelemProgAux(_, K, K, R, R).
subKelemProgAux(L, K, Len, [H|T], R):- candidat1(L, E),
                                       E < H,
                                       progresie([E|[H|T]]),
                                       Len1 is Len + 1,
                                       subKelemProgAux(L, K, Len1, [E|[H|T]], R).

progresie([_,_]):-!.
progresie([H1,H2,H3|T]):- abs(H1-H2) =:= abs(H2-H3),
                          progresie([H2,H3|T]).

main11(L, K, R):- findall(C, submultimiKelemProg(L, K, C), R).


% 12) lista aranjamentelor cu N elemente care se termină cu o valoare
% impară și au suma S dată
% ex: L=[2,7,4,5,3], N=2 și S=7 => [[2,5], [4,3]]

aranjNValImp(L, N, S, R):- candidat1(L, E),
                           E mod 2 =:= 1,
                           E =< S,
                           aranjNValImpAux(L, N, S, 1, E, [E], R).

aranjNValImpAux(_, N, S, N, Sum, R, R):- Sum = S.
aranjNValImpAux(L, N, S, Len, Sum, [H|T], R):- Sum < S,
                                               candidat1(L, E),
                                               Sum1 is Sum + E,
                                               Len1 is Len + 1,
                                               aranjNValImpAux(L, N, S, Len1, Sum1, [E|[H|T]], R).

main12(L, N, S, R):- findall(C, aranjNValImp(L, N, S, C), R).


% 13) lista submulţimilor de sumă pară, cu elementele unei liste.
% ex: L=[2, 3, 4] => [[],[2],[4],[2,4]]

sumaPara(_, []).
sumaPara(L, R):- candidat1(L, E),
                 sumaParaAux(L, E, [E], R).

sumaParaAux(_, Sum, R, R):- Sum mod 2 =:= 0.
sumaParaAux(L, Sum, [H|T], R):- candidat1(L, E),
                                E < H,
                                Sum1 is Sum + E,
                                sumaParaAux(L, Sum1, [E|[H|T]], R).

main13(L, R):- findall(C, sumaPara(L, C), R).


% 14) lista subşirurilor cu cel puțin 2
% elemente, formate din elemente în ordine strict crescătoare
% [1,8,6,4]=>[[1,8],[1,6],[1,4],[6,8],[4,8],[4,6],[1,4,6],[1,4,8],[1,6,8],[4,6,8],[1,4,6,8]]

subsirElemCresc(L, R):- candidat1(L, E),
                        subsirElemCrescAux(L, 1,[E], R).

subsirElemCrescAux(_, Len, R, R):- Len >= 2.
subsirElemCrescAux(L, Len, [H|T], R):- candidat1(L, E),
                                       E < H,
                                       Len1 is Len + 1,
                                       subsirElemCrescAux(L, Len1, [E|[H|T]], R).

main14(L, R):- findall(C, subsirElemCresc(L, C), R).

