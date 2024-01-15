; 11

; a) Sa se determine cel mai mic multiplu comun al valorilor numerice dintr-o lista neliniara.

; cmmmc

(defun cmmdc (a b)
    (cond
        ((not (numberp a)) b)
        ((not (numberp b)) a)
        ((= 0 b) a)
        ((= a b) a)
        ((> a b) (cmmdc b (- a b)))
        (t (cmmdc a (- b a)))
    )
)

(defun cmmmc (a b)
    (cond
        ((not (numberp a)) b)
        ((not (numberp b)) a)
        (t (/ (* a b) (cmmdc a b)))
    )
)

(cmmmc '5 '6)

(defun cmmmc_lista (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (cmmmc (cmmmc_lista (car l)) (cmmmc_lista (cdr l))))
        ((not (numberp (car l))) (cmmmc_lista (cdr l)))
        (t (cmmmc ( car l) (cmmmc_lista (cdr l))))
    )
)

(cmmmc_lista '(4 5 6 (2 A)))

; c) Sa se elimine toate aparitiile elementului numeric maxim dintr-o lista neliniara.

(defun maxim (a b)
    (cond
        ((not (numberp a)) b)
        ((not (numberp b)) a)
        ((> a b) a)
        (t b)
    )
)

(defun element_maxim (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (maxim (element_maxim (car l)) (element_maxim (cdr l))))
        (t (maxim (car l) (element_maxim (cdr l))))
    )
)

(element_maxim '(1 4 5 A 56 34 78 66))

(defun eliminare_element (l elem)
    (cond
        ((null l) nil)
        ((listp (car l)) (cons (eliminare_element (car l) elem) (eliminare_element (cdr l) elem)))
        ((eq (car l) elem) (eliminare_element (cdr l) elem))
        (t (cons (car l) (eliminare_element (cdr l) elem)))
    )
)

(eliminare_element '(1 2 3 2 1 1 1 1 2 3 2 345 6 3) '1)

(defun eliminare_element_maxim (l)
    (eliminare_element l (element_maxim l))
)

(eliminare_element_maxim '(1 2 3 2 1 1 1 1 2 3 2 345 6 345))

; d) Sa se construiasca o functie care intoarce produsul atomilor numerici pari dintr-o lista, de la orice nivel.

(defun produs_pare (l)
    (cond
        ((null l) 1)
        ((listp (car l)) (* (produs_pare (car l)) (produs_pare (cdr l))))
        ((AND (numberp (car l)) (eq (mod (car l) 2) 0)) (* (car l) (produs_pare (cdr l))))
        (t (produs_pare (cdr l)))
    )
)

(produs_pare '(1 2 3 4 A (3 4 G H I) 2))