; 3.

; a) Definiti o functie care intoarce produsul a doi vectori.

; produs_vectori(l1...ln, k1...km) = { nil, l vida 
;                                    { (l1 * k1) U produs_vectori(l2...ln, k2...km)

(defun produs_vectori (l k)
    (cond
        ((OR (null l) (null k)) nil)
        (t (cons (* (car l) (car k)) (produs_vectori (cdr l) (cdr k))))
    )
)

(produs_vectori '(1 2 3) '(7 2 3))

; b) Sa se construiasca o functie care intoarce adancimea unei liste.

; max(a b) = { a, a > b
;              { b, altfel

(defun max (a b)
    (cond 
        ((> a b) a)
        (t b)
    )
)

; adancime_lista(l1...ln, i) = { i, n = 0
;                              { max( adancime_lista(l1, i+1) adancime_lista(l2...ln), i), l1 lista
;                              { adancime_lista(l2...ln, i)

(defun adancime_lista (l i)
    (cond
        ((null l) i)
        ((listp (car l)) (max (adancime_lista (car l) (+ 1 i)) (adancime_lista (cdr l) i)))
        (t (adancime_lista(cdr l) i))
    )
)

(adancime_lista '(1 2 3 (4) 5 (6 (7 (8)))) 0) ; => 3
(adancime_lista '(0 3 2 (a)) 0) ; => 1

; c) Definiti o functie care sorteaza fara pastrarea dublurilor liniara.

; sterge_element(l1...ln, e) = { nil, lista vida
;                              { l1 U sterge_element(l2...ln, e), l1 != e
;                              { sterge_element(l2...ln, e), altfel

(defun sterge_element (l e)
    (cond
        ((null l) nil)
        ((not( eq (car l) e)) (append (list(car l)) (sterge_element (cdr l) e)))
        (t (sterge_element (cdr l) e))
    )
)

; min(l1...ln, m) = { m, n = 0
;                   { m(l2...ln, l1), l1 < m
;                   { m(l2...ln, m)

(defun min(l m)
    (cond
        ((null l) m)
        ((< (car l) m) (min (cdr l) (car l)))
        (t (min (cdr l) m))
    )
)

(defun minW(l)
    (min l (car l))
)

; sortare(l1...ln) = { nil, l vida
;                    { minW(l) U sortare(sterge_element(l minW(l))), altfel

(defun sortare(l)
    (cond
        ((null l) nil)
        (t (append (list(minW l)) (sortare ( sterge_element l (minW l)))))
    )
)

(sortare '(5 4 32 12 23 12 45 22))

; d) Sa se scrie o functie care intoarce intersectia a doua multimi.

; apartine (l1...ln a) = { nil, l vida
;                        { apartine(l1, a) || apartine(l2...ln, a), l1 lista
;                        { TRUE, l1 = a
;                        { apartine(l2...ln, a)

(defun apartine (l a)
    (cond
        ((null l) nil)
        ((listp (car l)) (OR (apartine (car l) a) (apartine (cdr l) a)))
        ((equal (car l) a) T)
        (t (apartine (cdr l) a))
    )
)

; intersectie(l1...ln, k1...km) = { nil, l1 null
;                                 { l1 U intersectie(l2...ln, k), daca apartine(k l1)
;                                 { intersectie(l2...ln, k) 

(defun intersectie (l k)
    (cond
        ((null l) nil)
        ((apartine k (car l)) (cons (car l) (intersectie (cdr l) k)))
        (t (intersectie (cdr l) k))
    )
)