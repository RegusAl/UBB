; 12

; a) Definiti o functie care intoarce produsul scalar a doi vectori.

(defun produs_vectori (l k)
    (cond
        ((null l) nil)
        (t (cons (* (car l) (car k)) (produs_vectori (cdr l) (cdr k))))
    )
)

(produs_vectori '(1 2 3) '(4 5 6))

; b) Sa se construiasca o functie care intoarce maximul atomilor numerici dintr-o lista, de la orice nivel.

(defun maxim (a b)
    (cond
        ((not(numberp a)) b)
        ((not(numberp b)) a)
        ((> a b) a)
        (t b)
    )
)

(maxim '622 '12)

(defun maxim_atomi (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (maxim (maxim_atomi (car l)) (maxim_atomi (cdr l))))
        (t (maxim (car l) (maxim_atomi (cdr l))))
    )
)

(maxim_atomi '(1 2 3 (4 3) ((456)) 2 3))

; d) Sa se scrie o functie care intoarce T daca o lista are numar par de elemente pe primul nivel si NIL in caz contrar, fara sa se numere elementele listei.

(defun nr_par (l)
    (cond
        ((null l) t)
        ((not (null (cadr l))) (nr_par (cddr l)))
        (t nil)
    )
)

(nr_par '(1 (2 3)))