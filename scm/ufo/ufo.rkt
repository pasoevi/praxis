#lang racket

(require 2htdp/universe 2htdp/image)

(struct position (x y))

(define WIDTH 640)
(define HEIGHT 400)
(define INITIAL-POSITION (position 95 15))
(define VELOCITY 2)
(define WHEEL_SKEW 8)
(define BG-COLOUR "gray")
(define IMAGE-of-UFO (bitmap "ufo.png"))
(define IMAGE-of-SMOKE (bitmap "smoke.png"))
(define IMAGE-of-GAME-OVER (bitmap "gameover.png"))





(define (move-left p)
  (cons (position
   (- (position-x (car p)) WHEEL_SKEW)
   (position-y (car p))) (cdr p)))

(define (move-right p)
  (cons (position
   (+ (position-x (car p)) WHEEL_SKEW)
   (position-y (car p))) (cdr p)))


(define (move-up p)
  (cons (position
   (position-x (car p))
   (- (position-y (car p)) WHEEL_SKEW)) (cdr p)))

(define (move-down p)
  (cons (position
   (position-x (car p))
   (+ (position-y (car p)) WHEEL_SKEW)) (cdr p)))

(define (run-down p)
  (cons (position
   (position-x (car p))
   (+ (position-y (car p)) VELOCITY)) (append (cdr p) (list (car p)))))

; takes a list of positions first of which is the position of 
; the ufo and an arbitrary number of positions of the gray trails
; it leaves. 
(define (draw-ufo-onto-an-empty-scene positions)
  (define ufo (car positions))
     (define trails (cdr positions))
     (define scene 
       (for/fold ([scn (empty-scene WIDTH HEIGHT BG-COLOUR)]) 
                   ([trail trails])
                     (place-image IMAGE-of-SMOKE (position-x trail) 
                  (position-y trail)
                  scn)))
    (place-image IMAGE-of-UFO (position-x ufo) (position-y ufo)
               scene))

(define (draw-game-over current-state)
  (place-image IMAGE-of-GAME-OVER (/ WIDTH 2) (/ HEIGHT 2)
               (empty-scene WIDTH HEIGHT)))

(define (state-is-300 p)
  (>= (position-y (car p)) HEIGHT))

(define (handle-wheel p key)
  (cond [(key=? key "left") (move-left p)]
        [(key=? key "right") (move-right p)]
        [(key=? key "up") (move-up p)]
        [(key=? key "down") (move-down p)]
        [(key=? key "q") (stop-with p)]
        [else p]))

(big-bang (list INITIAL-POSITION INITIAL-POSITION)
          (on-tick run-down)
          (on-key handle-wheel)
          (to-draw draw-ufo-onto-an-empty-scene)
          (stop-when state-is-300 draw-game-over))

