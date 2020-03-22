#lang racket
(require 2htdp/batch-io)
(define (convert in out)
  (write-file out
   (number->string 
    (f2c
     (string->number (read-file in))))))
  (define (f2c n)
    (* 5/9 (- n 32)))

(convert "in" "out")