; 8

; a) Sa se elimine elementul de pe pozitia a n-a a unei liste liniare.

(defun eliminare (l n poz)
    (cond
        ((null l) nil)
        ((eq n poz) (cdr l))
        (t (cons (car l) (eliminare (cdr l) n (+ 1 poz))))
    )
)

(defun eliminareW (l n)
    (eliminare l n 1)
)

; b) Definiti o functie care determina succesorul unui numar reprezentat cifra cu cifra intr-o lista. De ex: (1 9 3 5 9 9) --> (1 9 3 6 0 0)

; inverare lista
(defun inversare (l)
    (cond
        ((null l) nil)
        (t (append (inversare (cdr l)) (list (car l))))
    )
)

(defun succesor (l)
    (cond
        ((null l) nil)
        ((equal (car l) 9) (cons '0 (succesor (cdr l))))
        (t (cons (+ 1 (car l)) (cdr l)))
    )
)

(defun zecimala (l)
    (cond
        ((equal (car l) 0) (cons '1 l))
        (t l)    
    )
)

(defun w (l)
    (zecimala(inversare(succesor (inversare l))))
)

; c) Sa se construiasca multimea atomilor unei liste.Exemplu: (1 (2 (1 3 (2 4) 3) 1) (1 4)) ==> (1 2 3 4)

(defun liniarizare (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (append (liniarizare (car l)) (liniarizare (cdr l))))
        (t (append (list (car l)) (liniarizare (cdr l))))
    )
)

(defun construire (l)
    (liniarizare l)
)