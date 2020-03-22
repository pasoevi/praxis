(define-module (bilang))
(export parse)
(export interpreter)

(define (parse sexp)
	 (cond
	  ((number? sexp) sexp)
	  ((list? sexp)
	   (case (car sexp)
	     ((add) (+ (parse (cadr sexp)) (parse (caddr sexp))))
	     ((sub) (- (parse (cadr sexp)) (parse (caddr sexp))))
	     ((mul) (* (parse (cadr sexp)) (parse (caddr sexp))))
	     ((div) (/ (parse (cadr sexp)) (parse (caddr sexp))))))))



(define (interpreter)
  (begin
    (display "> ")
    (display (parse '3)))
    (newline)
    (interpreter)))

(interpreter)


