#lang racket

(require net/smtp)

(smtp-send-message "smpt.gmail.com"
                   "s.pasoev@pear.ge"
                   '("s.pasoev@gmail.com")
                   ""
                   "Hello!"
                   #:auth-user "s.pasoev@pear.ge"
                   #:auth-passwd "GloriaPerpetua9")