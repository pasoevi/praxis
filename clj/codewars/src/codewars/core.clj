(ns codewars.core
  (:require [codewars.persistence :refer :all]
            [codewars.avg :refer :all])
  (:gen-class))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Testing average")
  (println (find-average [1 2 3]))
  (println "Testing persistence")
  (println (persistence (read-string (first args)))))

