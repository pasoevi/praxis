#lang racket

(define ls (string->list (file->string "input.txt")))


(let ([lefts (length (filter (lambda (x) (char=? x #\()) ls))]
      [rights (length (filter (lambda (x) (char=? x #\))) ls))])
  (- lefts rights))

