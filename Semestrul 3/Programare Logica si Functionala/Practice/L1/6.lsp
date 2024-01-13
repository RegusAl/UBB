; 6

; a) Sa se scrie de doua ori elementul de pe pozitia a n-a a unei liste liniare. De exemplu, pentru (10 20 30 40 50) si n=3 se va produce (10 20 30 30 40 50).

; dublareN(l1...ln, n, poz) = { nil, l vida
;                             { l1 U l1 U l2...ln, poz = n
;                             { l1 U dublare(l2...ln, n, poz + 1)

(defun dublareN (l n poz)
    (cond
        ((null l) nil)
        ((eq poz n) (append (list (car l) (car l)) (cdr l)))
        (t (append (list (car l)) (dublareN (cdr l) n (+ 1 poz))))
    )
)

(defun dublareNW (l n)
    (dublareN l n 1)
)

; b) Sa se scrie o functie care realizeaza o lista de asociere cu cele doua liste pe care le primeste. De ex: (A B C) (X Y Z) --> ((A.X) (B.Y) (C.Z)).

; asociere(l1..ln, k1..km) = { nil, l null
;                            { (l1, k1) U asociere(l2..ln, k2..km)

(defun asociere (l k)
    (cond
        ((null l) nil)
        (t (cons (cons (car l) (car k)) (asociere (cdr l) (cdr k))))
    )
)

; c) Sa se determine numarul tuturor sublistelor unei liste date, pe orice nivel. Prin sublista se intelege fie lista insasi, fie un element de pe orice nivel, care este lista. Exemplu: (1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 (lista insasi, (3 ...), (4 5), (6 7), (9 10)).

; nrSubliste(l1...ln) = { 1, lista vida
;                       { nrSubliste(l1) + nrSubliste(l2...ln), l1 e lista
;                       { nrSubliste(l2...ln) 

(defun nrSubliste (l)
    (cond
        ((null l) 1)
        ((listp (car l)) (+ (nrSubliste (car l)) (nrSubliste (cdr l))))
        (t (nrSubliste (cdr l)))
    )
)

; d) Sa se construiasca o functie care intoarce numarul atomilor dintr-o lista, de la nivel superficial.

; nratomi(l1...ln) = { 0, nil
;                    { 1 + nratomi(l2...ln), l1 atom
;                    { nratomi(l2...ln), l1 lista

(defun nratomi (l)
    (cond
        ((null l) 0)
        ((listp (car l)) (nratomi (cdr l)))
        (t (+ 1 (nratomi (cdr l))))
    )
)