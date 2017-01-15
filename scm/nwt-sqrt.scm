;; (define (nwt-sqrt guess x)
;; 	 (if (= (* guess guess) x)
;; 	     guess
;; 	     (nwt-sqrt (/ (+ guess (/ x guess)) 2) x)))

(define (new-if predicate then-clause else-clause)
	 (cond (predicate then-clause)
	       (else else-clause)))

(define (close-enough? guess x)
  (< (abs (- x (* guess guess))) 0.00000000000000000000001))

(define (average x y)
  (/ (+ x y) 2))

(define (improve guess x)
  (average guess (/ x guess)))


(define (my-sqrt x)
  (nwt-sqrt 1.0 x))


(define (improve-cube guess x)
  (/ (+ (/ x (* guess guess)) (* 2 guess)) 3))

(define (close-enough-cube? guess x)
  (< (abs (- x (* guess guess guess))) 0.00000000000001))

(define (nwt-cube-root guess x)
  (if (close-enough-cube? guess x)
      guess
      (nwt-cube-root (improve-cube guess x)
		     x)))


(define (improve guess x)
  (average guess (/ x guess)))


(define (nwt-sqrt guess x)
  (if (close-enough? guess x)
      guess
      (nwt-sqrt (improve guess x)
		x)))


;; (nwt-sqrt 1.0 4)

;; (nwt-sqrt (improve 1.0 4) 4)

;; (improve 1.0 4)


;;  1.0 + 4/1.0   2.5
;; -------------
;;       2

;; (nwt-sqrt 2.5 4)

(define (square x)
  (* x x))

(define (sqrt x)
  (define (good-enough? guess)
    (< (abs (- x (square guess))) 0.000000000000001))
  (define (improve guess)
    (average guess (/ x guess)))
  (define (nwt-sqrt guess)
    (if (good-enough? guess)
	guess
	(nwt-sqrt (improve guess))))
  (nwt-sqrt 1.0))
