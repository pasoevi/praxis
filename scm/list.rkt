#lang racket

(define lst (append (list 1 2 3) (list 12 13 14)))

(define improper-lst (append '(1 2 3) 4))

(car lst)

(car improper-lst)


