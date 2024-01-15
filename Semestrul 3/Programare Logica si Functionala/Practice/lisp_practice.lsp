; 1 

; Se consideră o listă neliniară. Să se scrie o funcţie LISP care să aibă ca rezultat lista iniţială în care toate apariţiile unui
; element ​e ​au fost înlocuite cu o valoare ​e1​. ​Se va folosi o funcție MAP.
; Exemplu
; a) ​dacă lista este (1 (2 A (3 A)) (A)) ​e ​este A şi ​e1​ este B => (1 (2 B (3 B)) (B))

(defun inlocuire (l e subs)
    (cond
        ((AND (atom l) (not (equal l e))) l)
        ((AND (atom l) (equal l e)) subs)
        (t (mapcar #'(lambda (x) (inlocuire x e subs)) l))
    )
)

(inlocuire '(1 (2 A (3 A)) (A)) 'A 'B)

; 2

; Să se substituie un element ​e prin altul ​e1 la orice nivel impar al unei liste neliniare. Nivelul superficial se consideră 1. De
; exemplu, pentru lista (1 d (2 d (d))), e
; ​=d şi ​e1​=f rezultă lista (1 f (2 d (f))).

(defun substituire (l e e1 niv)
    (cond
        ((AND (atom l) (not (eq l e))) l)
        ((AND (atom l) (eq (mod niv 2) 0)) e)
        ((AND (atom l) (eq (mod niv 2) 1)) e1)
        (t (mapcar #'(lambda(x) (substituire x e e1 (+ 1 niv))) l))
    )
)

(defun main_2 (l e e1)
    (substituire l e e1 0)
)

(main_2 '(1 d (2 d (d))) 'd 'f)

; 3

; Se consideră o listă neliniară. Să se scrie o funcţie care să aibă ca rezultat lista iniţială in care atomii de pe nivelul ​k ​au fost
; înlocuiți cu 0 (nivelul superficial se consideră 1). ​Se va folosi o funcție MAP.
; Exemplu​ pentru lista (a (1 (2 b)) (c (d)))
; a) ​k=2 => (a (0 (2 b)) (0 (d)))
; b
; )​ k=1 => (0 (1 (2 b)) (c (d)))
; c)​ k=4 =>lista nu se modifică

(defun inlocurire3 (l k niv)
    (cond
        ((AND (atom l) (not (eq k niv))) l)
        ((AND (atom l) (eq k niv)) 0)
        (t (mapcar #'(lambda(x) (inlocurire3 x k (+ 1 niv))) l))
    )
)

(defun main3 (l k)
    (inlocurire3 l k 0)
)

(inlocurire3 '(a (1 (2 b)) (c (d))) '0 '1)

(main3 '(a (1 (2 b)) (c (d))) 4)



; eliminare atomi nenumerici de pe niv pare

(defun elimina (l niv)
    (cond
        ((AND (atom l) (numberp l)) l)
        ((AND (atom l) (not(numberp l)) (eq (mod niv 2) 0)) nil)
        ((AND (atom l) (not(numberp l)) (eq (mod niv 2) 1)) l)
        (t (mapcar #'(lambda (x) (elimina x (+ niv 1))) l))
    )
)

(defun elim (l niv)
    (cond
        ((AND (atom l) (equal (mod niv 2) 0)) (list l))
        ((AND (atom l) (equal (mod niv 2) 1)) NIL)
        (t(mapcan #'(lambda (x)
            ( elim x (+ niv 1) )) l
        ))
    )
)