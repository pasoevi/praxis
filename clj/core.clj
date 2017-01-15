(ns learn.core)
(require 'clojure/string)

(defn euclid
  "Return the greatest common divisor"
  [m n]
  (if (> n 0)
    (euclid n (mod m n))
    m))

(defn change-case
  "Make uppercase letters lowercase and make lowercase letters uppercase"
  [c]
  c)

(defn square
  [x]
  (* x x))

(defn pwr
  "Return the value of r in the power of p"
  [r p]
  (if (odd? p)
    (* r (pwr r (- p 1)))
    (square (pwr r (/ p 2)))))

(pwr 4 2)
