(ns codewars.cubes
  (:gen-class))

(defn exp [x n]
  (reduce *' (repeat n x)))

(def get-nth-cube
  (memoize (fn [n]
             (if (= n 1) 1
                 (+' (*' n n n) (get-nth-cube (-' n 1)))))))

(defn find-nb [m]
  (loop [n 1]
    (cond (= m (get-nth-cube n)) n
          (> m (get-nth-cube n)) (recur (+' n 1))
          :else -1)))


;; (defn find-nb [m]
;;   (let [find-nb-rec (fn find-nb-rec [n]
;;                       (cond (= m (get-nth-cube n)) n
;;                             (> m (get-nth-cube n)) (find-nb-rec (+ n 1))
;;                             :else -1))]
;;     (find-nb-rec 1)))  


;; (defn find-nb [m]
;;   (loop [cube-at-n 1
;;          n 1]
;;     (cond (= m cube-at-n) n
;;           (> m cube-at-n) (recur (+ cube-at-n (get-nth-cube (+ n 1))) (+ n 1))
;;           :else -1)))
