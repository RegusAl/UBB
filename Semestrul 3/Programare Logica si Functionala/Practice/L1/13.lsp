; 13

; a) Sa se intercaleze un element pe pozitia a n-a a unei liste liniare.

(defun intercalare (l n elem poz)
    (cond
        ((null l) nil)
        ((eq n poz) (cons elem (cdr l)))
        (t (cons (car l) (intercalare (cdr l) n elem (+ 1 poz))))
    )
)

(intercalare_main '(1 2 3 4 5) 3 88)

(defun intercalare_main (l n elem)
    (intercalare l n elem 1)
)

; b) Sa se construiasca o functie care intoarce suma atomilor numerici dintr-o lista, de la orice nivel.

(defun suma (l)
    (cond
        ((null l) 0)
        ((listp (car l)) (+ (suma (car l)) (suma (cdr l))))
        ((numberp (car l)) (+ (car l) (suma (cdr l))))
        (t (suma (cdr l)))
    )
)

(suma '(1 2 3 (4 5 a)))

; c) Sa se scrie o functie care intoarce multimea tuturor sublistelor unei liste date. Ex: Ptr. lista ((1 2 3) ((4 5) 6)) => ((1 2 3) (4 5) ((4 5) 6))

(defun multime (l)
    (cond
        ((atom l) nil)
        (T (apply 'append (list l) (mapcar 'multime l)))
    )
)

(multime '(A (B C (D))))

; d) Sa se scrie o functie care testeaza egalitatea a doua multimi, fara sa se faca apel la diferenta a doua multimi.

(defun apare (l elem)
    (cond
        ((null l) nil)
        ((eq (car l) elem) t)
        (t (apare (cdr l) elem))
    )
)

(apare '(1 2 3 4) '5)

(defun stergere (l elem)
    (cond
        ((null l) nil)
        ((eq (car l) elem) (cdr l))
        (t (cons (car l) (stergere (cdr l) elem)))
    )
)

(stergere '(1 2 3 4) '7)

(defun egalitate (l k)
    (cond
        ((AND (null l) (null k)) t)
        ((apare l (car k)) (egalitate (cdr k) (stergere l (car k))))
        (t nil)
    )
)

(egalitate '(1 2) '(1 ))