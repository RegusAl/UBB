; 16. Sa se decida daca un arbore de tipul (2) este echilibrat (diferenta dintre adancimile celor 2 subarbori nu este mai mare decat 1).

(defun numar_niveluri (l)
    (cond
        ((null l) 0)
        ((null (cdr l)) 1)
        (t (+ 1 (max (numar_niveluri (cadr l)) (numar_niveluri (caddr l)))))
    )
)

(defun echilibrat (l)
    (cond
        ((null l) t)
        (t (AND ( < (abs (- (numar_niveluri (cadr l)) (numar_niveluri (caddr l)))))))
    )
)