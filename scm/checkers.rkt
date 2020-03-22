#lang slideshow

(define (four p)
  (define two-p (hc-append p p))
  (vc-append two-p two-p))

(define (square a)
  (filled-rectangle a a))

(four (rectangle 10 10))

(define (checker p1 p2)
  (let ([p12 (hc-append p1 p2)]
        [p21 (hc-append p2 p1)])
    (vc-append p12 p21)))

(checker (colorize (square 10) "red")
         (colorize (square 10) "black"))

(define (checkboard p)
  (let* ([rp (colorize p "red")]
         [bp (colorize p "black")]
         [c (checker rp bp)]
         [c4 (four c)])
    (four c4)))

(define (series mk)
  (hc-append 4 (mk 5) (mk 10) (mk 20)))

(define series-2
  (lambda (mk) (hc-append 4 (mk 5) (mk 10) (mk 20))))

(series (lambda (size) (checkboard (square size))))

(provide series square)