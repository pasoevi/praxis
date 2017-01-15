#lang racket

(require 2htdp/universe)
(require 2htdp/image)


(define (render w)
  (text (number->string w) 12 "black"))

(big-bang 100
	(on-tick sub1)
        (on-draw render)
	(stop-when zero?))
