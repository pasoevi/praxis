#lang racket

;; Returns the number of the top level elements of the list
(define (all-length lst)
  (if (null? lst)
      0
      (add1 (all-length (cdr lst)))))

;; Returns the number of elements in the list including all subelements recursively
(define (all-length2 lst)
  (cond 
    [(null? lst) 0]
    [(list? (car lst)) (+ (all-length2 (car lst)) (all-length2 (cdr lst)))]
    [else (add1 (all-length2 (cdr lst)))]))

(all-length2  '(a (b c (c a) a )a a))
(all-length2 '(a (b c) (d (e f))))

;; Returns the smallest number of the list
(define (my-min lst)
  (if (= 1 (all-length lst))
      (car lst)
      (let ([frst (car lst)]
            [min-rest (my-min (cdr lst))])
        (if (< frst min-rest)
            frst
            min-rest))))

(my-min '(1 3 4 8 2 98 -5))
;; Returns the greatest number of the list
(define (my-max lst)
  (if (= 1 (all-length lst))
      (car lst)
      (let ([frst (car lst)]
            [max-rest (my-max (cdr lst))])
        (if (> frst max-rest)
            frst
            max-rest))))

(my-max '(1 3 4 8 2 98 -5))

;; Returns a 2-element list of the smallest and the largest numbers in the list given. 
(define (range lst)
  (list (my-min lst) (my-max lst)))

(range '(0 7 8 2 3 -1))
(range '(7 6 5 4 3))