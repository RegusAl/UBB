; 5

; a) Definiti o functie care interclaseaza cu pastrarea dublurilor doua liste liniare sortate.

; interclasare(l1...ln, k1...km) = { nil, l si k vide
;                                  { l1 U interclasare(l2...ln, k1...km), l1 < k1
;                                  { k1 U interclasare(l1...ln, k2...km), l1 > k1
;                                  { k, l vida
;                                  { l, k vida

(defun interclasare (l k)
    (cond
        ((null l) k)
        ((null k) l)
        ((< (car l) (car k)) (cons (car l) (interclasare (cdr l) k)))
        (t (cons (car k) (interclasare l (cdr k))))

    )
)

; b) Definiti o functie care substituie un element E prin elementele unei liste L1 la toate nivelurile unei liste date L.

; inlocuire(l1...ln, L1, e) = { nil, l vida
;                             { L1 U inlocuire(l2...ln, L1, e), daca l1 = e
;                             { inlocuire(l1, L1, e) U inlocuire(l2...ln, L1, e), daca l1 e lista
;                             { l1 U inlocuire(l2...ln, L1, e), altfel 

(defun inlocuire (l l1 e)
    (cond
        ((null l) nil)
        ((listp (car l)) (cons (inlocuire (car l) l1 e) (inlocuire (cdr l) l1 e)))
        ((eq (car l) e) (cons l1 (inlocuire (cdr l) l1 e)))
        (t (cons (car l) (inlocuire (cdr l) l1 e)))
    )
)

; c) - nope

; d) Definiti o functie care intoarce cel mai mare divizor comun al numerelor dintr-o lista liniara.

; cmmdc(a b) = { a, b = 0
;              { a, a = b
;              { cmmdc(b, a-b), a > b
;              { cmmdc(a, b-a), b > a 

(defun cmmdc (a b)
    (cond
        ((not (numberp a)) b)
        ((not (numberp b)) a)
        ((eq b 0) a)
        ((eq a b) a)
        ((> a b) (cmmdc b (- a b)))
        ((> b a) (cmmdc a (- b a)))
    )
)


; lista_cmmdc(l1...ln) = { nil, l = vida
;                        { cmmdc(lista_cmmdc(l1), lista_cmmdc(l2...ln))
;                        { lista_cmmdc(l2...ln), l1 nu e numar
;                        { cmmdc(l1, lista_cmmdc(cdr l))

(defun lista_cmmdc (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (cmmdc (lista_cmmdc (car l)) (lista_cmmdc (cdr l))))
        ((not (numberp (car l))) (lista_cmmdc (cdr l)))
        (t (cmmdc (car l) (lista_cmmdc (cdr l))))
    )
)