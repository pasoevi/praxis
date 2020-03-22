#lang racket

(require db)

(define mc (mysql-connect #:server "localhost"
                 #:port 3306
                 #:database "blue_bank"
                 #:user "sergi"
                 #:password "wattlebird"))




  
(define (accounts)
  (let ([query-users "SELECT * FROM users"])
    ((for ([(id first_name fast_name id_national current_amount phone) (in-query mc query-users)])
  (printf "~a: ~a\n" first_name current_amount)))))

(define (names)
  (let ([query-names "SELECT first_name FROM users"])
    (query-list mc query-names)))

(provide accounts names)