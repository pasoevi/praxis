#lang racket

(define name 'sergi)

(define (who name)
  (cond
    [(symbol=? name 'sergi) "Hello Sergi"]
    [(symbol=? name 'sophie) "Hello Sophie"]
    [else "Hi there"]))

(define-struct posn (x y))

(define (square x)
  (* x x))

(define (distance-to-zero posn)
  (sqrt
   (+ (square (posn-x posn))
      (square (posn-y posn)))))


"Sergi"
