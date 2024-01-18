; 9.
; Definiti o functie care substituie un element E prin elementele unei liste L1 la toate nivelurile unei liste date L.

; substituire (l, e, l1) = { l, daca l e atom si l != e
;                          { l1, daca l e atom si l = e
;                          { substituire(l1) U ... U substituire(ln)

(defun substituire (L E L1)
  (cond
    ((and (not (equal L E)) (atom L))  L)
    ((and (equal L E) (atom L)) L1)
    (t (mapcar #' (lambda(x) (substituire X E L1)) L))
  )
)

(substituire '(1 2 3 1 5 6 7) 1 '(2 3))

(substituire '(1 2 3 1 (5 6 3) (3) 7) 3 '(2 3))