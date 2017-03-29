#lang racket
(define people (list (cons "Sergi" "Surami") (cons "Petre" "Borjomi") (cons "Lika" "Kareli")))

(define pirveli car)
(define meore cdr)
(define cxovrobs? string=?)
      

(define (mivide-tu-davreko? x)
  (if (cxovrobs? (meore x) "Surami")
      (list (pirveli x) "Midi")
      (list (pirveli x) "Daureke")))

(map mivide-tu-davreko? people)