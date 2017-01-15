#lang racket/base

(require rackunit
	 "length.rkt")

(check-equal? (my-length '()) 0 "checking an empty list")
(check-equal? (my-length null) 0)
(check-equal? (my-length '(a)) 1) 
(check-equal? (my-length '(a b)) 2)
