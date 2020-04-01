#lang racket
(require 2htdp/image
	 2htdp/universe)
;; Orc Battle - A game from the Realm of Racket book.

;; Constant definitions
(define MAX-HEALTH 35)
(define MAX-AGILITY 35)
(define MAX-STRENGTH 35)

;; Data definitions
(struct orc-world (player lom attack#) #:mutable)
(struct player (health agility strength))
(struct monster ([health #:mutable]))

;; Monster definitions
(struct orc monster (club))

(struct hydra monster ())
(struct slime monster (sliminess))
(struct brigand monster ())


