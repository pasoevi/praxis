#lang racket

(define *simple-grammar* '((sentence -> (noun-phase verb-phase))
                           (noun-phase -> (article noun))
                           (verb-phase -> (verb noun-phase))
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
  (rule-rhs (assoc category *grammar*)))


(define (generate phrase)
  "Generate a random sentence or phrase"
  )