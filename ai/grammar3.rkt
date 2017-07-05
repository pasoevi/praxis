#lang racket

#|
  A simple grammar parser.
|#

(require "list.rkt")

(define *simple-grammar* '((sentence -> (noun-phrase verb-phase))
                           (noun-phrase -> (article noun))
                           (verb-phrase -> (verb noun-phrase))
                           (article -> the a)
                           (noun -> man ball woman table)
                           (verb -> hit took saw liked)))

(define *grammar* *simple-grammar*)

(define (rule-lhs rule)
  "The left-hand side of a rule"
  (first rule))

(define (rule-rhs rule)
  "The right-hand side of a rule"
  (rest (rest rule)))

(define (rewrites category)
  "Return a list of the possible rewrites for this category"
  (if (assoc category *grammar*)
      (rule-rhs (assoc category *grammar*))
      #f))

(define (generate phrase)
  "Generate a random sentence or phrase"
  (display (list phrase (list? phrase)))
  (newline)
  ;; (newline)
  (cond [(list? phrase) (map generate phrase)]
        [(rewrites phrase) (generate (random-elt (rewrites phrase)))]
        [else (list phrase)]))

(generate 'sentence)