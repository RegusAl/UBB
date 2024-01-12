; 4

; a) Definiti o functie care intoarce suma a doi vectori.

; suma_vectori(l1...ln, k1...km) = { 0, l si k vida
;                                  { l1 + k1 U suma_vectori(l2...ln, k2...km), altfel

(defun suma_vectori (l k)
    (cond
        ((OR (null l) (null k)) nil)
        (t (cons (+ (car l) (car k)) (suma_vectori (cdr l) (cdr k))))
    )
)

; b) Definiti o functie care obtine dintr-o lista data lista tuturor atomilor care apar, pe orice nivel, dar in aceeasi ordine. De exemplu:(((A B) C) (D E)) --> (A B C D E)

; lista_atomi(l1...ln) = { nil, l vida
;                        { l1

(defun lista_atomi (l) 
    (cond
        ((null l) nil)
        ((listp (car l)) (append (lista_atomi (car l)) (lista_atomi (cdr l))))
        (t (cons (car l) (lista_atomi (cdr l))))
    )
)

; c) Sa se scrie o functie care plecand de la o lista data ca argument, inverseaza numai secventele continue de atomi. Exemplu:(a b c (d (e f) g h i)) ==> (c b a (d (f e) i h g))

(defun inverseaza_continuele (l aux)
  (cond
    ((null l) aux)

    ;daca e lista adaug la final de aux, am terminat cu actuala inversare si lipesc car l inversat si cdr l inversat (appenduite)
    ((listp (car l)) (append aux (append (list (inverseaza_continuele (car l) nil)) (inverseaza_continuele (cdr l) nil))))

    ;adaug practic la inceput de aux -> 1 2 3 va fi 3 2 1 ca adaug la inceput de fiecare data
    (t (inverseaza_continuele (cdr l) (append (list (car l)) aux)))
  )
)

; d) Sa se construiasca o functie care intoarce maximul atomilor numerici dintr-o lista, de la nivelul superficial.

; maxim(l1...ln, m) = { m, l vida
;                     { maxim(l2...ln, l1), l1 nu e lista si l1 > m
;                     { maxim(l2....ln, m), altfel

(defun maxim (l m)
    (cond
        ((null l) m)
        ((AND (numberp (car l)) (> (car l) m)) (maxim (cdr l) (car l)))
        (t (maxim (cdr l) m))
    )
)

(defun maximW (l)
    (maxim l -9999)
)