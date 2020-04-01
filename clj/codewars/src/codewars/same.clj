(ns codewars.squares
  (:gen-class))

(defn square? [n]
  (integer? (Math/sqrt n)))

(defn divisors [n]
  (for [d (range 1 n)
        :when (= (mod n d) 0)]
        d))

(defn sum-squared-divisors [n]
  (reduce + (map #(* % %) (divisors n))))

(defn list-squared [m n]
  (for [x (range m n)
        :let [div-sqr-sum (sum-squared-divisors x)]
         :when (square? div-sqr-sum)]
    [x div-sqr-sum]))
