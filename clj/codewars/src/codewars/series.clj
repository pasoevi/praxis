(ns codewars.series
  (:gen-class))

(defn series-sum-rec [n]
  (cond (<= n 0) (double 0)
        :else (double
          (+ 
            (/ 1 (+ (* (- n 1) 3 ) 1))
            (series-sum-rec (- n 1))))))

(def series-sum-memo (memoize series-sum-rec))

(defn series-sum [n]
  (format "%.2f" (series-sum-memo n)))
