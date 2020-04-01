(define (square x)
  (* x x))

(define (sum ls)
  (if (null? ls)
      0
      (+ (car ls) (sum (cdr ls)))))

(define (max x y)
  (if (>= x y)
    x
    y))

(define (largest-two x y z)
  (define first-half (max x y))
  (define second-half (max y z))
  (list first-half (max second-half (max x z))))

(define (sum-of-two-squares x y z)
  (sum (map square (largest-two x y z))))

(define (square-of-sum-qf-squares x y)
  ((square (+ (square x) (square y)))))

;; Applicative order

(square-of-sum-of-two-squares 4 5)

(square (+ (square 4) (square 5)))

(* (+ (square 4) (square 5)) (+ (square 4) (square 5)))

(* (+ (* 4 4) (* 5 5)) (+ (* 4 4) (* 5 5)))

(* ( + 16 25) (+ 16 25))

(* 41 41) 

;; Substitition model

(square-of-sum-of-two-squares 4 5)

(square (sum (square 4) (square 5)))

(square (sum (16) (25)))

(square (41))

