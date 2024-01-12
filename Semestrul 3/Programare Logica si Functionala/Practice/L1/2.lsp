; 2.

; a) Definiti o functie care selecteaza al n-lea element al unei liste, sau NIL, daca nu exista.

; exista (l1...ln, x, poz) = { nil, l vida
;                            { l1, poz = x
;                            { exista(l2...ln, x, poz+1)

(defun exista (l x poz)
    (cond
        ((null l) nil)
        ((eq poz x) (car l))
        (t (exista (cdr l) x (+ 1 poz)))
    )
)

; wrapper

(defun existaW (l x)
    (exista l x 1)
)

; b) Sa se construiasca o functie care verifica daca un atom e membru al unei liste nu neaparat liniara.

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

; c) Sa se construiasca lista tuturor sublistelor unei liste. Prin sublista se intelege fie lista insasi, fie un element de pe orice nivel, care este lista. Exemplu: (1 2 (3 (4 5) (6 7)) 8 (9 10)) => ( (1 2 (3 (4 5) (6 7)) 8 (9 10)) (3 (4 5) (6 7)) (4 5) (6 7) (9 10) ).

; subliste(l1...ln) = { nil, l atom
;                     { l1 + subliste(car(l1...ln))

(defun subliste (l)
    (cond
        ((atom l) nil)
        (t (apply 'append (list l) (mapcar 'subliste l)))
    )
)

(subliste '(1 2 (3 (4 5) (6 7)) 8 (9 10)))

; d) Sa se scrie o functie care transforma o lista liniara intr-o multime.

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

(sterge_element '(1 5 3 4 5) 5)

; multime (l1...ln) = { nil, lista vida
;                     { l1 U sterge_element(l2...ln, l1), altfel

(defun multime (l)
    (cond
        ((null l) nil)
        (t (append (list(car l)) (multime (sterge_element l (car l)))))
    )
)

(multime '(1 2 3 2 3 3 3 4 5 6 7 6 7))
