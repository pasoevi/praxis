#lang racket

;; Vocabulary
(define nouns '(antilope elephant dog cat man woman))
(define verbs '(barks reads jumps))

;; List functions
(define (one-of set)
  "Pick one element of set, and make a list of it"
  (list (random-elt set)))

(define (random-elt choices)
  "Choose an alement from a list at random"
  (list-ref choices (random (length choices))))

(define (contains ls elem)
  "Check if ls contains element elem"
  (> (length (filter (λ (x) (= x elem)) ls)) 0))

;; String functions
(define (starts-with str c)
  "Check whether c is the first character of str. Case insensitive"
  (if (char-ci=? (string-ref str 0) c) #t #f))

;; Grammar functions
(define (vowel? c)
  (member c (list #\a #\e #\i #\o #\u)))

(define (article noun)
  "Pick a correct article given a noun"
  (if (vowel? (string-ref (symbol->string (first noun)) 0)) '(an) '(a)))

(define (noun) (one-of nouns))
(define (verb) (one-of verbs))

(define (noun-phase)
  (let ([some-noun (noun)])
    (append (article some-noun) some-noun)))

(define (verb-phase)
  (append (verb) (noun-phase)))

(define (sentence)
  (append (noun-phase) (verb-phase)))

(sentence)
