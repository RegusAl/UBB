; 14. Sa se construiasca lista nodurilor unui arbore de tipul (2) parcurs in postordine.

; SDR 

(defun postordine (arb)
    (cond
        ((null arb) nil)
        ((null (cdr arb)) (list (car arb)))
        (t (append (postordine (cadr arb)) (postordine (caddr arb)) (list (car arb))))
    )
)