#lang racket

(define (d/dx f)
  (define d (/ 100000))
  (lambda (x)
    (/ (- (f (+ x d)) (f (- x d))) 2 d)))