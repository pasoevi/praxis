(ns Player
  (:gen-class))
  (use '[clojure.string :only [index-of]])

; The while loop represents the game.
; Each iteration represents a turn of the game
; where you are given inputs (the heights of the mountains)
; and where you have to print an output (the index of the mountain to fire on)
; The inputs you are given are automatically updated according to your last actions.

(defn output [msg] (println msg) (flush))
(defn debug [msg] (binding [*out* *err*] (println msg) (flush)))

(defn -main [& args]
  (while true
    (let [mountains (repeatedly 8 read)
          tallest (reduce max mountains)]
        (println (str (index-of mountains tallest)))
        (println "LKJLKJ")
    )))