; 14

; a) Dandu-se o lista liniare, se cere sa se elimine elementele din N in N.

(defun eliminare_n (l n poz)
    (cond
        ((null l) nil)
        ((eq n poz) (eliminare_n (cdr l) n 1))
        (t (cons (car l) (eliminare_n (cdr l) n (+ 1 poz))))
    )
)

(eliminare_n '(1 2 3 4 5 6 7 8 9 10) '2 '1)

; c) Sa se construiasca o functie care intoarce minimul atomilor numerici dintr-o lista, de la orice nivel.

(defun minim (a b)
    (cond
        ((not(numberp a)) b)
        ((not(numberp b)) a)
        ((< a b) a)
        (t b)
    )
)

(minim '-90 '0)

(defun lista_minim (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (minim (lista_minim (car l)) (lista_minim (cdr l))))
        ((numberp (car l)) (minim (car l) (lista_minim (cdr l))))
        (t (lista_minim (cdr l)))
    )
)

(lista_minim '(1 2 3 (A -90) -900 2455))

; d) Sa se scrie o functie care sterge dintr-o lista liniara toate aparitiile elementului maxim numeric.

(defun maxim (a b)
    (cond
        ((not (numberp a)) b)
        ((not (numberp b)) a)
        ((> a b) a)
        (t b)
    )
)

(defun lista_max (l)
    (cond
        ((null l) nil)
        (t (maxim (car l) (lista_max (cdr l))))
    )
)

(lista_max '(1 2 3 564 231 345))

(defun stergere_max (l elem)
    (cond
        ((null l) nil)
        ((eq (car l) elem) (stergere_max (cdr l) elem))
        (t (cons (car l) (stergere_max (cdr l) elem)))
    )
)

(defun main_stergere_max (l)
    (stergere_max l (lista_max l))
)

(main_stergere_max '(1 2 3 445 231 2 24 445 45))