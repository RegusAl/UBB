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
        ; cadr l = (car (cdr l))
        ; caddr l = (car (cdr (cdr l)))
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
        ; daca numarul nodurilor de pe nivelul i este 0 => 0
        ((= (lungime (nivel_k l i)) 0) 0)
        ; daca nr nodurilor de pe nivelul i > nr nodurilor de pe i+1  => i
        ((> (lungime (nivel_k l i)) (lungime (nivel_k l (nivelNrNoduriMaxim l (+ i 1))))) i)

        (t (nivelNrNoduriMaxim l (+ i 1)))
    )
)


; main(l1...ln) = { nivelNrNoduriMaxim(l1...ln, 0) U nivel_k(l1...ln, nivelNrNoduriMaxim(l1...ln, 0))

; main(L: list)
(defun main (l)
    (cons (nivelNrNoduriMaxim l 0) (nivel_k l (nivelNrNoduriMaxim l 0)))
)


; nivel 0: A
(main '(A))

; nivel 0: A
(main '(A (B)))

; nivel 2: D E F
(main '(A (B (D)) (C (E (G)) (F)))) 

; nivel 3: F G H I  
(main '(A (B (D (F) (G))) (C (E (H) (I)))))  

; nivel 1: B C
(main '(A (B) (C)))

; nivel 4: F G H
(main '(A (B (C (D (F)) (E (G) (H))))))

; nivel 5: G H S T
(main '(A (B (D (E (F (G) (H (J) (K)))))) (C (L (N (V (S) (T))) (Q (P) (R))))))
