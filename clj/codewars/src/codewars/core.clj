(ns codewars.core
  (:require [codewars.persistence :refer :all]
            [codewars.avg :refer :all]
            [codewars.weights :refer :all]
            [codewars.panagram :refer :all]
            [codewars.cubes :refer :all])
  (:gen-class))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Testing average")
  (println (find-average [1 2 3]))
  (println "Testing persistence")
  (println "Testing cubes")
  (println (pangram? "The quick brown fox jumps over the lazy dog."))
  ;; (println (get-nth-cube (read-string (first args))))
  ;;(println (find-nb (read-string (first args))))
  (println (order-weight "2000 10003 1234000 44444444 9999 11 11 22 123")))

