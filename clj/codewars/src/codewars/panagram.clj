(ns codewars.panagram
  (:gen-class))
 
(require '[clojure.string :as str])

(defn in? 
  "true if coll contains elm"
  [coll elm]
(some (partial = elm) coll))

(defn contains-many? [ls ks]
  (every? #(in? ls %) ks))

(defn char-range [start end]
  (map char (range (int start) (inc (int end)))))

(defn pangram?
  [s]
  (let [str-seq (map str (seq (str/lower-case s)))
    all-chars (map str (char-range \a \z))]
    (contains-many? str-seq all-chars)))