; aspect de munte

(defun creste (l)
    (cond
        ((null l) t)
        ((null (cadr l)) t)
        ((< (car l) (cadr l)) (creste (cdr l)))
        (t nil)
    )
)

(defun scade (l)
    (cond
        ((null l) t)
        ((null (cadr l)) t)
        ((> (car l) (cadr l)) (scade (cdr l)))
        (t nil) 
    )
)



(defun crestem (l maxim)
    (cond
        ((null l) t)
        ((null (cadr l)) t)
        ((AND (car l) maxim) t)
        ((< (car l) (cadr l)) (crestem (cdr l) maxim))
        (t nil)
    )
)

(defun scadem (l)
    (cond
        ((null l) t)
        ((null (cadr l)) t)
        ((> (car l) (cadr l)) (scadem (cdr l)))
        (t nil) 
    )
)

(creste '(1 2 3 2))

(scade '(32 3))

(maxim_lista '(1 2 3  55 66 4) '1)

(main '(10 18 29 17 11 20 10) '29 0)



(cddr '(1 2 3 4 5))


(crestem '(1 2 3 2) '3)



(defun maxim_lista (l maxim)
    (cond
        ((null l) maxim)
        ((> (car l) maxim) (maxim_lista (cdr l) (car l)))
        (t (maxim_lista (cdr l) maxim)) 
    )
)


(defun main (l maxim aux)
    (cond
        ((null l) t)
        ((AND(null (cadr l)) (= aux 1)) t)
        ((AND(< (car l) (cadr l)) (< (car l) maxim) (= aux 0)) (main (cdr l) maxim 0))
        ((AND(> (car l) (cadr l)) (< (car l) maxim) (= aux 1)) (main (cdr l) maxim 1))
        ((eq (car l) maxim) (main (cdr l) maxim 1))
        (t nil)
    )
)

(defun munte (l)
    (main l (maxim_lista l (car l)) '0)
)

(munte '(10 18 29 11 3))  ; True

(munte '(10 9 8 7 8 9 10))  ; NIL

(munte '(1 2 3 4 5 6 7 8 10 9 20))  ; NIL

(munte '(1 2 3 2 1))  ; T

(munte '(5 6 5 4 3 2 1))