(ns play.core
  (:require [play.coll :refer :all]
            [play.graph :refer :all]))

(defn foo
  "I don't do a whole lot."
  [x]
  (println x "Hello, World!"))

(defn my-add [a b]
  (+ a b))

(defn whole-name [& args]
  (let [{:keys [f-name m-name l-name]} args]
    (str l-name ", " f-name " " m-name)))

(defn -main [& args]
  (println (index [4 5 2 3 4 2])))

