
; a) Definiti o functie care intoarce produsul a doi vectori.

; produs_vectori(x1...xn, z1...zm) = { nil, daca n = 0 sau m = 0
;                                    { x1*z1...zm, daca n = 1
;                                    { x1*z1...xn, daca m = 1
;                                    { x1*z1 U produs_vectori(x2...xn, z2...zm)

; produs_vectori(L1: list, L2: list)
(defun produs_vectori (l1 l2)
  (cond
    ((or (null l1) (null l2)) nil)
    ((null (cdr l1)) (cons (* (car l1) (car l2))(cdr l2)))
    ((null (cdr l2)) (cons (* (car l1) (car l2))(cdr l1)))
    (t (cons (* (car l1) (car l2)) (produs_vectori (cdr l1) (cdr l2))))
  )
)

(produs_vectori '(1 2 3) '(4 5 6))


; b) Sa se construiasca o functie care intoarce adancimea unei liste.

; maxim(x, y) = { x, x > y
;               { y, altfel

; maxim(x: int, y: int)
(defun maxim (x y)
    (cond
        ((> x y) x)
        (t y)
    )
)


; adancime(l1...ln, a) = { a = 0, n = 0
;                        { maxim(adancime(l1, a + 1), adancime(l2...ln, a)), daca l1 este lista
;                        { adancime(l2...ln), altfel

; adancime(L: list, a: int)
(defun adancime (l a)
    (cond
        ((null l) a)
        ((listp (car l)) (maxim (adancime (car l) (+ a 1)) (adancime (cdr l) a)))
        (t(adancime (cdr l) a))
    )
)

(adancime '() 0)
(adancime '(1 2 (3 4 5 (6 7) 5) 4) 0)
(adancime '(3 2 (1) (4 (5)))  0)
(adancime '(1 2 ((3) (4)) 5 6) 0)

; adancimew(l1...ln) = { 0, n = 0
;                      { adancime(l1...ln, 0)

; adancimew(L: list)
(defun adancimew (l)
    (cond
     ((null l) 0)
     (t (adancime l 0))
    )
)

(adancimew '(1 (2) 3 4))
(adancimew '(1 2 (3 4 5 (6 7) 5) 4))
(adancimew '(3 2 (1) (4 (5))))
(adancimew '(1 2 ((3) (4)) 5 6))


; c) Definiti o functie care sorteaza fara pastrarea dublurilor liniara.

; inserare(l1...ln, e) = { [e], n = 0
;                        { e U l1...ln, e < l1
;                        { l1...ln, e = l1
;                        { l1 U inserare(l2...ln, e), altfel

; inserare(L: list, e: int)
(defun inserare (l e)
    (cond
        ((null l) (list e))
        ((< e (car l))(cons e l))
        ((= e (car l)) l)
        (t(cons (car l) (inserare (cdr l) e)))
    )
)

(inserare '(1 2 3 4 5) '3)
(inserare '() 4)


; sortare(l1...ln) = { nil, n = 0
;                    { inserare(sortare(l2...ln), l1), altfel

; sortare(L: list)
(defun sortare (l)
    (cond
        ((null l) nil)
        (t (inserare (sortare (cdr l)) (car l)))
    )
)

(sortare '(1 2 1))
(sortare '(5 6 89 4 5 3 2 4 2 1))
(sortare '(3 2 1 2 3 4 3 2 1))

; d) Sa se scrie o functie care intoarce intersectia a doua multimi.

; exista(l1...ln, e) = { nil, n = 0
;                      { true, e = l1
;                      { exista(l2...ln, e), altfel

; exista(l: list, e: element)
(defun exista (l e)
    (cond
        ((null l) nil)
        ((equal (car l) e) t)
        (t(exista (cdr l) e))
    )
)

; intersectie(x1...xn, z1...zm) = { nil, n = 0 sau m = 0
;                                 { x1 U intersectie(x2...xn, z1...zm), daca exista(x1, z1...zm) = true
;                                 { intersectie(x2...xn, z1...zm), altfel

; intersectie(x: list, z: list)
(defun intersectie (x z) 
    (cond
        ((or (null x) (null z)) nil)
        ((exista z (car x)) (cons (car x) (intersectie (cdr x) z)))
        (t(intersectie (cdr x) z))
    )
)

(intersectie '(1 2 3 4) '(2 3 5 6))
(intersectie '(1 2) '(3 4))
(intersectie '(1 2 3 4))