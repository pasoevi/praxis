(ns command-line-args.core)

(require 'clojure.java.io)

(defn foo
  "I don't do a whole lot."
  [x]
  (println x "Hello, World!"))

(defn parse-args [args]
  (into {} (map (fn [[k v]] [(keyword (.replace k "--" "")) v])
        (partition 2 args))))

(defn my-fib [n]
  (cond (= n 1) 1
        (= n 2) 2
        (> n 2) (+ (my-fib (- n 2)) (my-fib (- n 1)))))
(my-fib 4)

