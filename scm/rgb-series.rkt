#lang slideshow

(require "checkers.rkt")

(define (rgb-series mk)
  (vc-append
   (series (lambda (sz) (colorize (mk sz) "red")))
   (series (lambda (sz) (colorize (mk sz) "green")))
   (series (lambda (sz) (colorize (mk sz) "blue")))))

(rgb-series circle)

(define (rgb-maker mk)
  (lambda (sz)
    (vc-append 10 (colorize (mk sz) "red")
                (colorize (mk sz) "green")
                (colorize (mk sz) "blue"))))



(series (rgb-maker circle))
(series (rgb-maker square))

(define circle-sizes (list 10 20 30))

(define (rainbow p)
  (map (lambda (color)
         (colorize p color))
       (list "red" "orange" "yellow" "green" "blue" "indigo" "violet")))

(rainbow (square 10))

(define (box)
  (map (lambda (size)
         (square size))
       circle-sizes))

(box)

(apply hc-append (rainbow (filled-rectangle 50 50)))