(ns codewars.template
  (:gen-class))

(defn template [s]
  (fn [mp]
    (doseq [keyval mp] (re (key keyval) (val keyval)))))


