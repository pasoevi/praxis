#lang racket
(define lower 1)
(define upper 100)

(define (guess-my-number)
  (quotient (+ lower upper) 2))
(define (smaller)
  (set! upper (sub1 (guess-my-number)))
  (guess-my-number))

(define (bigger)
  (set! lower (add1 (guess-my-number)))
  (guess-my-number))

(define (start-over)
  (set! lower 1)
  (set! upper 100)
  (guess-my-number))
