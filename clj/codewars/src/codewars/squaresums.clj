(ns codewars.squaresums
  (:gen-class))

(defn square? [n]
  (let [sqrt-n (Math/sqrt n)]
    (not (or (> sqrt-n (int sqrt-n)) (< sqrt-n (int sqrt-n))))))

(defn divisors [n]
  (for [d (range 1 (+ 1 n))
        :when (= (mod n d) 0)]
    d))

(defn sum-squared-divisors [n]
  (reduce + (map #(* % %) (divisors n))))

(defn list-squared [m n]
  (sort #(compare (first %1) (first %2))
        (for [x (range m n)
              :let [div-sqr-sum (sum-squared-divisors x)]
              :when (square? div-sqr-sum)]
          [x div-sqr-sum])))

