(ns codewars.template
  (:gen-class))

(defn template [s]
  (fn [mp]
    (doseq [keyval mp] (map (key keyval) (val keyval)))))


