; 15

; a) Sa se scrie o functie care intoarce reuniunea a doua multimi.

(defun apare (l elem)
    (cond
        ((null l) nil)
        ((eq (car l) elem) t)
        (t (apare (cdr l) elem))
    )
)

(defun reuniune (l k)
    (cond
        ((null k) l)
        ((not(apare l (car k))) (cons (car k) (reuniune l (cdr k))))
        (t (reuniune l (cdr k)))
    )
)

(reuniune '(1 2 3 4) '(5 6 3 2))

; b) Sa se construiasca o functie care intoarce produsul atomilor numerici dintr-o lista, de la orice nivel.

(defun produs (l)
    (cond
        ((null l) 1)
        ((listp (car l)) (* (produs (car l)) (produs (cdr l))))
        ((numberp (car l)) (* (car l) (produs (cdr l))))
        (t (produs (cdr l)))
    )
)

(produs '(1 2 3 (A 2) C D))

; c) Definiti o functie care sorteaza cu pastrarea dublurilor o lista liniara.

(defun inserare (l elem)
    (cond
        ((null l) (list elem))
        ((OR (< elem (car l)) (= elem (car l))) (cons elem l))
        (t (cons (car l) (inserare (cdr l) elem)))
    )
)

(inserare '(2 3 4) '3)

(defun sortare (l)
    (cond
        ((null l) nil)
        (t (inserare (sortare (cdr l)) (car l)))
    )
)

(sortare '(4 5 3 4))

; d) Definiti o functie care construiește o listă cu pozițiile elementului minim dintr-o listă liniară numerică.

(defun minim (a b)
    (cond
        ((not(numberp a)) b)
        ((not(numberp b)) a)
        ((< a b) a)
        (t b)
    )
)


(defun lista_minim (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (minim (lista_minim (car l)) (lista_minim (cdr l))))
        ((numberp (car l)) (minim (car l) (lista_minim (cdr l))))
        (t (lista_minim (cdr l)))
    )
)

(defun pozitii_minim (l min poz)
    (cond
        ((null l) nil)
        ((eq (car l) min) (cons poz (pozitii_minim (cdr l) min (+ 1 poz))))
        (t (pozitii_minim (cdr l) min (+ poz 1)))
    )
)

(pozitii_minim '(1 2 3 1 2 3 1 2 3) '1 '1)

(defun pozitii_minim_main (l)
    (pozitii_minim l (lista_minim l) 1)
)

(pozitii_minim_main '(1 2 3 4 5 4 3 2 1 1 1 ))