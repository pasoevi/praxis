(ns codewars.persistence
  (:gen-class))

(defn count-digits [n]
	"Count the number of digits in number n"
  (if (and (> n -10) (< n 10)) 1
      (+ 1 (count-digits (/ n 10)))))

(defn explode-to-digits [number]
	"Return a sequence of numbers that are the digits that maku up the given number"
  (map #(- (int %) (int \0)) (str number)))

(defn multiply-digits [n]
	"Return the product of digits that make up the number n"
  (reduce * (explode-to-digits n)))

(defn persistence [n]
	"Return the multiplication persistence of n - number of times you have
  to multiply digits of n until you get a one-digit number"
  (if (= (count-digits n) 1) 0
    	(+ 1 (persistence (multiply-digits n)))))
