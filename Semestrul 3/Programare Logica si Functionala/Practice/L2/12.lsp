; 12. Sa se construiasca lista nodurilor unui arbore de tipul (2) parcurs in preordine.

; RSD

(defun preordine (arb)
    (cond
        ((null arb) nil)
        ((null (cdr arb)) (list (car arb)))
        (t (append (list (car arb)) (preordine (cadr arb)) (preordine (caddr arb))))
    )
)