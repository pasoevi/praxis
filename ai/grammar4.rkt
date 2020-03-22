#lang racket

#|
A simple grammar parser.
|#

(require "list.rkt")

(define *simple-grammar* '((sentence -> (noun-phrase verb-phrase))
                           (noun-phrase -> (article noun))
                           (verb-phrase -> (verb noun-phrase))
                           (article -> the a)
                           (noun -> man ball woman table)
                           (verb -> hit took saw liked)))

(define *bigger-grammar* '((sentence -> (noun-phrase verb-phrase))
                           (noun-phrase -> (article adj* noun pp*) (name) (pronoun))
                           (verb-phrase -> (verb noun-phrase pp*))
                           (pp* -> () (pp pp*))
                           (adj* -> () (adj adj*))
                           (pp -> (prep noun-phrase))
                           (prep -> to in by with on)
                           (adj -> big little blue green adiabatic)
                           (article -> the a)
                           (name -> Pat Kim Lee Terry Robin)
                           (noun -> man ball woman table)
                           (verb -> hit took saw liked)
                           (pronoun -> he she it these those that)))
				     

(define *grammar* *bigger-grammar*)

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
  (let ([choices (rewrites phrase)])
    (cond [(list? phrase) (mappend generate phrase)]
          [choices (generate (random-elt choices))]
          [else (list phrase)])))

(define (generate-tree phrase)
  "Generate a random sentence or phrase with a complete parse tree"
  (let ([choices (rewrites phrase)])
    (cond [(list? phrase) (map generate-tree phrase)]
          [choices (cons phrase (generate-tree (random-elt choices)))]
          [else (list phrase)])))

(display (generate-tree 'sentence))
(newline)
(display (generate 'sentence))
(newline)
