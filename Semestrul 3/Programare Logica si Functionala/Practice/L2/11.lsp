; 11. Se da un arbore de tipul (2). Sa se afiseze nivelul (si lista corespunzatoare a nodurilor) avand numar maxim de noduri. Nivelul rad. se considera 0.

(defun nivelk (l k)
    (cond
        ((null l) NIL)
        ((= k 1) (list (car l)))
        (t (append (nivelk (cadr l) (- k 1)) (nivelk (caddr l) (- k 1))))
    )
)


(defun lungime (l)
    (cond
        ((null l) 0)
        (t (+ 1 (lungime (cdr l))))
    )
)

(defun nivel_max (l i)
    (cond
        ((= (lungime (nivelk l i)) 0) 0)
        ((> (lungime (nivelk l i)) (lungime (nivelk l (nivel_max l (+ i 1))))) i)
        (t (nivel_max l (+ i 1)))
    )
)