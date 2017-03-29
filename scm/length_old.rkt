#lang racket/base

(provide my-length)

(define (my-length lst)
  (if (null? lst)
    0
    (add1 (my-length (cdr lst)))))
