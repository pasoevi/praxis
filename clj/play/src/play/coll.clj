(ns play.coll)

(defn pos-1 [e coll]
  (let [cmp (if (map? coll)
	      ;; Map compare
	      #(= (second %1) %2)
	      ;; Default compare
	      #(= %1 %2))]
    ;; Start at the beginning
    (loop [s coll idx 0]
      ;; when not empty
      (when (seq s)
	(if (cmp (first s) e)
	  (if (map? coll)
	    (first (first s))
	    idx)
	  (recur (next s) (inc idx)))))))


(defn index [coll]
  (cond
   (map? coll) (seq coll)
   (set? coll) (map vector coll coll)
   :else (map vector (iterate inc 0) coll)))

(defn pos-2 [e coll]
  (for [[i v] (index coll) :when (= e v)] i))

(defn pos-3 [pred coll]
  (for [[i v] (index coll) :when (pred v)] i))

(defn sort-parts [work]
  (lazy-seq
   (loop [[part & parts] work]
     (if-let [[pivot & xs] (seq part)]
       (let [smaller?
	     #(< % pivot)]
	 (recur (list*
		 (filter smaller? xs)
		 pivot
		 (remove smaller? xs)
		 parts)))
       (when-let [[x & parts] parts]
	 (cons x (sort-parts parts)))))))

(defn qsort [xs]
  (sort-parts (list xs)))

(defn sum [xs]
  (loop [total 0
         i 0]
    (if (< i (count xs))
      (recur (+ total (nth xs i))
             (+ i 1))
      total)))

(println (sum [1 2 4]))

(println (reduce (fn [new-map [key val]]
                   (assoc new-map key (inc val)))
                 {}
                 {:one 0, :three 2}))

(defn my-map [f coll]
  (reduce (fn [new-col val]
            (conj new-col (f val)))
          []
          coll))

(defn my-filter [p coll]
  (reduce (fn [new-col val]
            (if (p val)
              (conj new-col val)
              new-col))
          []
          coll))

(my-map inc [1 2 3])
(my-map println {:key 1})
(filter even? [1 2 3])


(group-by #(< % 5) [1 2 3 4 5 6 7 7 ])

(def vampire-database
  {0 {:makes-blood-puns? false, :has-pulse? true  :name "McFishwich"}
   1 {:makes-blood-puns? false, :has-pulse? true  :name "McMackson"}
   2 {:makes-blood-puns? true,  :has-pulse? false :name "Damon Salvatore"}
   3 {:makes-blood-puns? true,  :has-pulse? true  :name "Mickey Mouse"}})

(defn vampire-related-details
  [social-security-number]
  (Thread/sleep 1000)
  (get vampire-database social-security-number))

(defn vampire?
  [record]
  (and (:makes-blood-puns? record)
       (not (:has-pulse? record))
       record))

(defn identify-vampire
  [social-security-numbers]
  (first (filter vampire?
                 (map vampire-related-details social-security-numbers))))

(time (identify-vampire (range 100000000)))
(time (odd? 4))

(take 3 (repeatedly #(rand-int 1000000010)))

(defn my-conj [target & elements]
  (into target elements))

(defn my-into [target additions]
  (apply conj target additions))

(defn my-partial [partialised-fn & args]
  (fn [& more-args]
    (apply partialised-fn (into args more-args))))

((my-partial + 5) 4)

;; partial
(defn lousy-logger [log-level message]
  (condp = log-level
    :warn (clojure.string/lower-case message)
    :error (clojure.string/upper-case message)))

(def warn (partial lousy-logger :warn))
(def error (partial lousy-logger :error))
(warn "File too large.")
(error "File not found.")

(defn my-cloj [target & elements]
  (into target elements))

;; demonstrating arity overloading
(defn sum
  ([vals] (sum vals 0))
  ([vals accumulating-total]
     (if (empty? vals)  
       accumulating-total
       (sum (rest vals) (+ (first vals) accumulating-total)))))

(sum [1 2 3 4])

:use java's random generator
(def random (java.util.Random.))
                                        ;define characters list to use to generate string
(def chars 
  (map char (concat (range 48 58) (range 66 92) (range 97 123))))
                                        ;generates 1 random character
(defn random-char [] 
  (nth chars (.nextInt random (count chars))))
                                        ; generates random string of length characters
(defn random-string [length]
  (apply str (take length (repeatedly random-char))))


;;


(def VALID-CHARS
  (map char (concat (range 48 58) ; 0-9
                    (range 66 91) ; A-Z
                    (range 97 123)))) ; a-z

(defn random-char []
  (nth VALID-CHARS (rand (count VALID-CHARS))))

(defn random-str [length]
  (apply str (take length (repeatedly random-char))))

(random-str 5)
(defn rand-entry
  [num]
  (str "prefWords[" num "] = \"" (random-str 6) "\";\n"))

(println (map #(rand-entry %) (range -30 30)))

(defn sum-tail
  [xs]
  (loop [sum 0
         vals xs]
    (if (empty? vals)
      sum
      (recur (+ sum (first vals)) (rest vals)))))

(sum-tail [1 2 3 4])

(defn sum-tail2
  ([xs]
     (sum-tail2 xs 0))
  ([xs accumulating-total]
     (if (empty? xs)
       accumulating-total
       (recur (rest xs) (+ (first xs) accumulating-total)))))

(sum-tail2 (range 2 3))
