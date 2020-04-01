(ns codewars.likes
  (:gen-class))

(defn likes [names]
  (cond (= (count names) 0) "no one likes this"
        (= (count names) 1) (format "%s likes this" (nth names 0))
        (= (count names) 2) (format "%s and %s like this" (nth names 0) (nth names 1))
        (= (count names) 3) (format "%s, %s and %s like this" (nth names 0) (nth names 1) (nth names 2))
        :else (format "%s, %s and %s others like this" (nth names 0) (nth names 1)  (- (count names) 2))))
