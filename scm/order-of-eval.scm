(define (p) (p))

(define (test x y)
  (if (= x y)
      0
      y))

(test 0 (p))

;; Aplicative-order

(if (= x 0)
    0
    y)

(if (= 0 0)
    0
    y)

(0)

;; Normal-order evaluation

(if (= x 0)
    0
    y)

(if (= x 0)
    0
    y)

