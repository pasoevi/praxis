(ns Solution
  (:gen-class))

; Auto-generated code below aims at helping you parse
; the standard input according to the problem statement.

(defn output [msg] (println msg) (flush))
(defn debug [msg] (binding [*out* *err*] (println msg) (flush)))

(defn -main [& args]
  (let [N (read)]
       [ls (sort (repeatedly N read))]
    (output (reduce #(< %1 %2) ls))))