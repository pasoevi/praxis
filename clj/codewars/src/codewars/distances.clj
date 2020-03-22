(ns codewars.avg
  (:gen-class))

(defn average [col]
  (/ (reduce + col) (count col)))

(defn distances-from-average [arr]
  (let [avg (average arr)]
    (map (fn [x] (- avg x)) arr)))
