; 11)
; Se da un arbore de tipul (2). Sa se afiseze nivelul (si lista corespunza-toarea nodurilor) avand numar maxim de noduri. Nivelul rad. se considera 0


; nivel_k(l1..ln, k) = { NIL, n = 0
;                      { [l1], k = 0
;                      { nivel_k (l2, k-1) U nivel_k (l3, k-1)

; nivel_k (L: list, K: int)
(defun nivel_k (l k)
    (cond
        ((null l) NIL)
        ((= k 0) (list (car l)))
        (t (append (nivel_k (cadr l) (- k 1)) (nivel_k (caddr l) (- k 1)) ) )
    )
)


; lungime(l1...ln) = { 0, n = 0
;                    { 1 + lungime(l2...ln)

; lungime(L: list)
(defun lungime (l)
    (cond
        ((null l) 0)
        (t (+ 1 (lungime (cdr l))))
    )
)


; nivelNrNoduriMaxim(l1...ln, i) = { 0, lungime(nivel_k(l1...ln, i)) = 0
;                                  { i, lungime(nivel_k(l1...ln, i) > lungime(nivel_k(l1...ln, nivelNrNoduriMaxim(l1...ln, i+1))))
;                                  { nivelNrNoduriMaxim(l, i+1)

; nivelNrNoduriMaxim(L: lista, i: int)
(defun nivelNrNoduriMaxim (l i)
    (cond
        ((= (lungime (nivel_k l i)) 0) 0)

        ((> (lungime (nivel_k l i)) (lungime (nivel_k l (nivelNrNoduriMaxim l (+ i 1))))) i)

        (t (nivelNrNoduriMaxim l (+ i 1)))
    )
)

; main(l1...ln) = { nivelNrNoduriMaxim(l1...ln, 0) U nivel_k(l1...ln, nivelNrNoduriMaxim(l1...ln, 0))

; main(L: list)
(defun main (l)
    (cons (nivelNrNoduriMaxim l 0) (nivel_k l (nivelNrNoduriMaxim l 0)))
)




(main '(A (B (D)) (C (E (G)) (F))))
