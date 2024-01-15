; 8. Sa se construiasca lista nodurilor unui arbore de tipul (2) parcurs in inordine.

; SRD
(defun inordine (arb)
    (cond
        ((null arb) nil)
        ((null (cdr arb)) (list (car arb)))
        (t (append (inordine (cadr arb)) (list (car arb)) (inordine (caddr arb))))
    )
)

(inordine '(A (B) (C (D) (E))))