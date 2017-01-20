(ns codewars.core
  (:require [codewars.persistence :refer :all])
  (:gen-class))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println (persistence (read-string (first args)))))

