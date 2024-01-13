; 7

; a) Sa se scrie o functie care testeaza daca o lista este liniara.

; testareLiniara(l1...ln) = { true, l vida
;                           { nil, l1 lista
;                           { testareLiniara(l2...ln)

(defun testareLiniara (l)
    (cond
        ((null l) T)
        ((listp (car l)) nil)
        (t (testareliniara (cdr l)))
    )
)

; c) Sa se inlocuiasca fiecare sublista a unei liste cu ultimul ei element. Prin sublista se intelege element de pe primul nivel, care este lista. Exemplu: (a (b c) (d (e (f)))) ==> (a c (e (f))) ==> (a c (f)) ==> (a c f) (a (b c) (d ((e) f))) ==> (a c ((e) f)) ==> (a c f)

; (defun inversare (l)
;     (cond
;         ((null l) nil)
;         ((listp (car l)) (append (inversare (cdr l)) (inversare (car l))))
;         (t (append (inversare (cdr l)) (list (car l))))
;     )
; )

; (defun inversareW (l)
;     (cond
;         ((null l) nil)
;         ((listp (car l)) (append (list (car (inversare (car l)))) (inversarew (cdr l))))
;         (t (append (list (car l)) (inversarew (cdr l))))
;     )
; )