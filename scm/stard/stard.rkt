#lang racket

(define (find-dictioraries dir)
  (for ([f (in-directory dir)] #:when (regexp-match? "\\.ifo$" f))
     (displayln f)))

(define dict-dir (expand-user-path "~/.dict"))

(find-dictioraries dict-dir)