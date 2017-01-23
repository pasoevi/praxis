(ns codewars.avg
  (:gen-class))

;; Write a function that returns the average of a set of numbers.
;; Be sure to return longs. We don't want to return Clojure Ratios!

(defn find-average
  [numbers]
  (float (/ (reduce + numbers) (count numbers))))


