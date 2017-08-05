#lang racket

(provide one-of random-elt contains mappend mapcar)

;; List functions
(define (one-of set)
  "Pick one element of set, and make a list of it"
  (list (random-elt set)))

(define (random-elt choices)
  "Choose an alement from a list at random"
  (list-ref choices (random (length choices))))

(define (contains ls elem)
  "Check if ls contains element elem"
  (> (length (filter (λ (x) (= x elem)) ls)) 0))

(define (mappend f ls)
  (apply append (map f ls)))

(define (mapcar f ls)
  (apply car (map f ls)))
