#lang racket

(require pict/flash)
(require "checkers.rkt")

(filled-flash 48 48)
(series (lambda (size) (square size)))
