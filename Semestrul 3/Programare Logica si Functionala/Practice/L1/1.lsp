; 1.

; a) Sa se insereze intr-o lista liniara un atom a dat dupa al 2-lea, al 4-lea, al 6-lea,....element.

; inserare(l1...ln, a, index) = { nil, n = vid
;                               { l1 U a U inserare(l2...ln, a, index+1), daca index e par
;                               { l1 U inserare(l2...ln, a, index + 1), altfel

(defun inserare (l a index)
    (cond
        ((null l) nil)
        ((eq (mod index 2) 0) (cons (car l) (cons a (inserare (cdr l) a ( + 1 index)))))
        (t (cons (car l) (inserare (cdr l) a (+ 1 index))))
    )
)

; b) Definiti o functie care obtine dintr-o lista data lista tuturor atomilor care apar, pe orice nivel, dar in ordine inversa. De exemplu: (((A B) C)(D E)) --> (E D C B A)

; lista_invers(l1..ln) = { nil, n = vid
;                        { lista_invers(l2...ln) U lista_invers(l1), l1 e lista
;                        { lista_invers(l2...ln) U [l1], altfel

(defun lista_invers (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (append (lista_invers(cdr l)) (lista_invers(car l))))
        (t (append (lista_invers(cdr l)) (list(car l))))
    )
)

; c) Definiti o functie care intoarce cel mai mare divizor comun al numerelor dintr-o lista neliniara.

; cmmdc (a, b) = { b, a not number
;                { a, b not number
;                { a, b = 0
;                { a, a = b
;                { cmmdc(b, a-b)
;                { cmmdc(a, b-a) 

(defun cmmdc (a b)
    (cond
        ((not (numberp a)) b)
        ((not (numberp b)) a)
        ((= 0 b) a)
        ((= a b) a)
        ((> a b) (cmmdc b (- a b)))
        (t (cmmdc a (- b a)))
    )
)

(cmmdc 20 15)   ; = 5
(cmmdc 30 100)  ; = 10

; lista_cmmdc(l1...ln) = { nil, l = vida
;                        { cmmdc(lista_cmmdc(l1), lista_cmmdc(l2...ln))
;                        { lista_cmmdc(l2...ln), l1 nu e numar
;                        { cmmdc(l1, lista_cmmdc(cdr l))

(defun lista_cmmdc (l)
    (cond
        ((null l) nil)
        ((listp (car l)) (cmmdc (lista_cmmdc (car l)) (lista_cmmdc (cdr l))))
        ((not (numberp (car l))) (lista_cmmdc (cdr l)))
        (t (cmmdc (car l) (lista_cmmdc (cdr l))))
    )
)

; d) Sa se scrie o functie care determina numarul de aparitii ale unui atom dat intr-o lista neliniara.

; nr_aparitii(l1...ln, x) = { 0, lista vida
;                           { nr_aparitii(car l1, x) + nr_aparitii(cdr l1, x), l1 e lista
;                           { 1 + nr_aparitii(l2...ln, x), l1 = x
;                           { nr_aparitii(l2...ln, x), altfel

(defun nr_aparitii (l x)
    (cond
        ((null l) 0)
        ((listp (car l)) (+ (nr_aparitii (car l) x) (nr_aparitii(cdr l) x)))
        ((eq (car l) x) (+ (nr_aparitii (cdr l) x) 1))
        (t (nr_aparitii (cdr l) x))
    )
)