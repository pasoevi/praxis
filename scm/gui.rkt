#lang racket

(require
  pict
  "db.rkt"
  racket/class
  racket/gui/base)


(define f (new frame% [label "Keep Goats"]
               [width 400]
               [height 400]
               [alignment '(center center)]))

(send f show #t)

; Make a static text message in the frame
(define msg (new message% [parent f]
                          [label "No events so far..."]))

(new list-box%	 
   	 	[label "names"]	 
   	 	[choices (names)]	 
   	 	[parent f])

; Make a button in the frame
(new button% [parent f]
             [label "Click Me"]
             ; Callback procedure for a button click:
             [callback (lambda (button event)
                         (send msg set-label "Button click"))])

#|
(define (add-drawing p)
  (let ([drawer (make-pict-drawer p)])
    (new canvas% 
         [parent f]
         [style '(border)]
         [paint-callback (lambda (self dc)
                           (drawer dc 0 0))])))

(add-drawing (circle 4))
|#