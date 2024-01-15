; 10. Se da un arbore de tipul (2). Sa se precizeze nivelul pe care apare un nodx in arbore. Nivelul radacii se considera a fi 0.

(defun apartine_arbore (l elem)
    (cond
        ((null l) nil)
        ((listp (car l)) (OR (apartine_arbore (car l) elem) (apartine_arbore (cdr l) elem)))
        ((eq elem (car l)) t)
        (t (apartine_arbore (cdr l) elem))
    )
)

(defun nivel_nod (l x)
    (cond
        ((null l) nil)
        ((equal (car l) x) 0)
        ((apartine_arbore (cadr l) x) ( + 1 (nivel_nod (cadr l) x)))
        ((apartine_arbore (caddr l) x) (+ 1 (nivel_nod (caddr l) x)))
        (t NIL)
    )
)