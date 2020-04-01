(ns codewars.weights
  (:gen-class))

(require '[clojure.string :as str])
(require '[codewars.persistence :as per])

(defn sum-digits [n]
  "Return the product of digits that make up the number n"
  (reduce + (per/explode-to-digits n)))

(defn weight-compare [a b]
  (let [a-sum (sum-digits a) b-sum (sum-digits b)]
    (if (= a-sum b-sum) (compare (str a) (str b))
        (compare a-sum b-sum))))

(defn order-weight [strng]
  (if (empty? strng) ""
      (let [lst (map read-string (str/split strng #" "))]
        (str/join " " (sort weight-compare lst)))))
