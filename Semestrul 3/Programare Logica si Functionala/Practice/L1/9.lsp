; 9

; a) Sa se scrie o functie care intoarce diferenta a doua multimi.

(defun exista (l elem)
    (cond
        ((null l) nil)
        ((eq (car l) elem) t)
        (t (exista (cdr l) elem))
    )
)

(exista '(1 2 3 4) 5)

(defun diferenta (l k) 
    (cond
        ((null l) nil)
        ((not(exista k (car l))) (cons (car l) (diferenta (cdr l) k)))
        (t (diferenta (cdr l) k))
    )
)

(diferenta '(5) '(3 4 5))

; b) Definiti o functie care inverseaza o lista impreuna cu toate sublistele sale de pe orice nivel.

(defun inversare (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (append (inversare (cdr l)) (list (inversare (car l)))))
        (t (append (inversare (cdr l)) (list (car l))))        
    )
)

(inversare '(1 2 3 4 (5 6)))

; d) Sa se construiasca o functie care intoarce suma atomilor numerici dintr-o lista, de la nivelul superficial.

(defun suma (l)
    (cond
        ((null l) 0)
        ((numberp (car l)) (+ (car l) (suma (cdr l))))
        (t (suma (cdr l)))
    )
)
