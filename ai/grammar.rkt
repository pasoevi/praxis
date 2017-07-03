#lang racket

(define articles '("the" "a" "an"))
(define nouns '("dog" "cat" "man" "woman"))
(define verbs '("banks" "reads" "jumps"))

(define (one-of set)
  "Pick one element of set, and make a list of it"
  (random-elt set))

(define (random-elt choices)
  "Choose an alement from a list at random"
  (list-ref choices (random (length articles))))

(define (contains ls elem)
  "Check if ls contains element elem"
  (> (length (filter (λ (x) (= x elem)) ls)) 0))

(define (article noun)
  "Pick a correct article given a noun"
  (display "Ok"))
  

(define (noun-phase)
  (let ([noun (list (one-of nouns))])
    (cons (one-of articles) noun)))

  (define (verb-phase)
    (list(one-of verbs)))

  (define (sentence)
    (append (noun-phase) (verb-phase)))

  (sentence)