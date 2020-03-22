#lang racket

(require 2htdp/universe 2htdp/image)

(define TEXT-SIZE 11)
(define SIZE 72)
(define WIDTH 800)
(define HEIGHT 600)
(define COLOR "red")

(define TEXT-X 10)
(define TEXT-UPPER-Y 5)
(define TEXT-LOWER-Y 585)

(struct interval (small big guesses))

(define HELP-TEXT
  (text "↑ for larger numbers, ↓ for smaller ones."
        TEXT-SIZE
        "blue"))

(define HELP-TEXT2
  (text "Press = when your number is guessed; q to quit"
        TEXT-SIZE
        "blue"))

;; Main screen
(define MT-SC
  (place-image/align
   HELP-TEXT TEXT-X TEXT-UPPER-Y "left" "top"
   (place-image/align
    HELP-TEXT2 TEXT-X TEXT-LOWER-Y "left" "bottom"
    (empty-scene WIDTH HEIGHT))))

;; This just modifies the world so that it is "single"
(define (guessed w)
  (interval (interval-small w)
            (interval-small w)
            (interval-guesses w)))

(define (guess w)
  (quotient (+ (interval-small w) (interval-big w)) 2))

(define (smaller w)
  (interval (interval-small w)
            (max (interval-small w) (sub1 (guess w)))
            (add1 (interval-guesses w))))

(define (bigger w)
  (interval (min (interval-big w) (add1 (guess w)))
            (interval-big w)
            (add1 (interval-guesses w))))


(define (render w)
  (overlay (text (number->string (guess w)) SIZE COLOR) MT-SC))


(define (render-last-scene w)
  (cond [(single? w) 
         (overlay 
          (text
           (string-append
            "Took me "
            (number->string (interval-guesses w))
            " tries. Wo!")
           SIZE COLOR) MT-SC)]
        [else
         (overlay (text "End" SIZE COLOR) MT-SC)]))

(define (single? w)
  (= (interval-small w) (interval-big w)))

;; Handle the key-press
;; w = world
(define (deal-with-guess w key)
  (cond [(key=? key "up") (bigger w)]
        [(key=? key "down") (smaller w)]
        [(key=? key "q") (stop-with w)]
        [(key=? key "=") (stop-with (guessed w))]
        [else w]))

(define (start lower upper)
  (big-bang (interval lower upper 1)
            (on-key deal-with-guess)
            (to-draw render)
            (stop-when single? render-last-scene)))


