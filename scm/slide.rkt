#lang slideshow

(require slideshow/code)
(t "Racket show")

(slide (t "This is a very unusual slideshow program")
       (code (+ 4 4))) 

(define-syntax pict-et-code
  (syntax-rules ()
    [(pict+code expr)
                  (hc-append 10
                             expr
                             (code expr))]))

(slide 
 (pict-et-code (circle 10)))

(provide pict-et-code)