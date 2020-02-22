(ns Solution
  (:gen-class))

; Auto-generated code below aims at helping you parse
; the standard input according to the problem statement.

(defn output [msg] (println msg) (flush))
(defn debug [msg] (binding [*out* *err*] (println msg) (flush)))

(defn to-zero
    [n]
    (Math/abs (- 0 (Math/abs n))))

(defn closer-to-zero
    [a b]
    (let [a-to-zero (to-zero a)
          b-to-zero (to-zero b)]
    (if (< a-to-zero b-to-zero) a b)))

(defn -main [& args]
  (let [n (read)
        temperatures (repeatedly n read)
        closest (if (empty? temperatures) 0 (reduce closer-to-zero temperatures))
        is-negative (< closest 0)]
    (if (empty? temperatures)
        (output 0)
        (if (and is-negative (.contains temperatures (Math/abs closest)))
            (output (Math/abs closest))
            (output closest)))))