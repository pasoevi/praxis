(define (my-reverse ls)
  (if (null? ls)
      ls
      (append (my-reverse (cdr ls)) (list (car ls)))))

(define (factorial n)
  (if (= n 1)
      1
      (* n (factorial (- n 1)))))

(factorial 4)

(factorial 1) -> 1

(fatrorial n) -> (factorial (- n 1))

()

(app\
