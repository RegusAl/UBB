; 10

; a) Sa se construiasca o functie care intoarce produsul atomilor numerici dintr-o lista, de la nivelul superficial.

(defun produs (l)
    (cond
        ((null l) 1)
        ((numberp (car l)) (* (car l) (produs (cdr l))))
        (t (produs (cdr l)))
    )
)

; b) Sa se scrie o functie care, primind o lista, intoarce multimea tuturor perechilor din lista. De exemplu: (a b c d) --> ((a b) (a c) (a d)(b c) (b d) (c d))

(defun perechi (l elem)
    (cond
        ((null l) nil)
        (t (cons (list elem (car l)) (perechi (cdr l) elem)))
    )
)

(perechi '(1 2 3 4) 5)

(defun perechiMain (l)
    (cond
        ((null l) nil)
        ((not (eq (cdr l) nil)) (append (perechi (cdr l) (car l)) (perechiMain (cdr l))))
        (t (perechiMain (cdr l)))
    )
)

(perechiMain '(1 2 3 4))

; d) Definiti o functie care, dintr-o lista de atomi, produce o lista de perechi (atom n), unde atom apare in lista initiala de n ori. De ex: (A B A B A C A) --> ((A 4) (B 2) (C 1)).

(defun aparitii (l e)
    (cond
        ((null l) 0)
        ((eq (car l) e) (+ 1 (aparitii (cdr l) e)))
        (t (aparitii (cdr l) e))
    )
)

(defun sterge_element (l e)
    (cond
        ((null l) nil)
        ((eq (car l) e) (sterge_element (cdr l) e))
        (t (cons  (car l) (sterge_element (cdr l) e)))
    )
)

(aparitii '(1 2 3 4 4 3 2 1 1) '56)

(sterge_element '(1 2 3 2 1 1 1) '1)

(defun lista_perechi (l)
    (cond
        ((null l) nil)
        (t (cons (list (car l) (aparitii l (car l))) (lista_perechi (sterge_element (cdr l) (car l)))))
    )
)

(lista_perechi '(A B A C B))