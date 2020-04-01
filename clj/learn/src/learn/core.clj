(ns learn.core
  (:gen-class))

(defn -main 
  "I don't do a whole lot ... yet."
  [name]
  (println (str "Hello, " name)))

(defn fib [n]
  (cond (= n 0) 0
        (= n 1) 1
        (= n 2) 2
        (> n 2) (+ (fib (- n 2)) (fib (- n 1)))))

(fib 5)

(defn who-add
  [a b]
  (+ a b))

(def m {:a 5 :b 6
        :c [7 8 9]
        :d {:e 10 :f 11}
        "foo" 88
        42 false})
(let [{a :a} m]
  (* a a))

(def map-in-vector ["James" {:birthday (java.util.Date. 73 1 6)}])

(def person {:name "Sergi Pasoev" :email "s.pasoev@gmail.com" :phone "557377770"})
  
(def user-info ["architect2562" 1997 :name "Sergi Pasoev" :city "Surami"])

(let [[username school-year & extra-info] user-info
		  {:keys [name city]} (apply hash-map extra-info)]
	      (str name " lives in " city))

(def my-adder (fn self-ref
                ([] 1)
                ([x] (self-ref x 1))
                ([x y] (+ x y))))

(letfn [(odd? [n]
          (even? (dec n)))
        (even? [n]
          (or (zero? n)
              (odd? (dec n))))]
  (odd? 5))

(defn make-user
  [username & {:keys [name email join-date] :or {join-date (java.util.Date.)}}]
  {:username username
   :name name
   :join-date join-date
   :email email
   :exp-date (java.util.Date. (long (+ 2.592e9 (.getTime join-date))))})

(defn naive-repl
  "Enter :quit to exit"
  []
  (println (str (ns-name *ns*) " >>> "))
  (flush)
  (let [expr (read)
        value (eval expr)]
    (when (not= :quit value)
      (println value)
      (recur))))

(require '[clojure.string :as str])

(def camel->keyword (comp keyword
                          str/join
                          (partial interpose \-)
                          (partial map str/lower-case)
                          #(str/split % #"(?<=[a-z])(?=[A-Z])")))

(def camel-pairs->maps (comp (partial apply hash-map)
                             (partial map-indexed
                                       (fn [i x]
                                         (if (odd? i)
                                           x
                                           (camel->keyword x))))))

(defn split-on-upper
  "Split given text on on every occurance of an upper-case letter"
  [x]
  (str/split x #"(?<=[a-z])(?=[A-Z])"))

(def my-camel->map (comp keyword
                         str/join
                         (partial interpose \-)
                         (partial map str/lower-case)
                         split-on-upper))

(defn doubler
  "doubles the result of calling the provided function"
  [f]
  (fn [& args]
    (* 2 (apply f args))))

(def doubler-+ (doubler +))

(defn print-logger
  "Returns a function that prints messages to the given writer"
  [writer]
  #(binding [*out* writer]
     (println %)))

(def *out*-logger (print-logger *out*))

(def memwriter (java.io.StringWriter.))

(def retained-writer (print-logger memwriter))
(retained-writer "Hi, memory")

(require 'clojure.java.io)

(def fname "learn.log")

(defn file-logger
  [file]
  "Write log messages to file"
  #(with-open [f (clojure.java.io/writer file :append true)]
     ((print-logger f) %)))

(def log->file (file-logger fname))

(defn multi-logger
  "Doesn't do logging by itself, but routes the task to the given
  logger functions"
  [& logger-fns]
  #(doseq [f logger-fns]
     (f %)))

(def verbose-multi-logger (multi-logger
                           log->file
                           retained-writer
                           *out*-logger))

(defn timestamped-logger
  [logger]
  #(logger (format "[%1$tY-%1$tm-%1$te %1$tH:%1$tM:%1$tS] %2$s" (java.util.Date.) %)))

(def log-timestamped (timestamped-logger verbose-multi-logger))

(def visitors (atom #{}))

(defn hello
  "Writes hello to *out*. Calls you by username. Knows if you have
  been here before"
  [username]
  (swap! visitors conj username)
  (str "Hello " username))

(hello "Sergi")

(defn testing
  []
  (println "Testing fast compilation"))

(let [x 4
      y (cond (> x 4) 5
        (= x 4) 3
        (< x 4) 1)]
  (println y))

(defn make-greeting
  [prefix]
  (fn [name]
    (str prefix " " name)))

(require '[clojure.string :as str])

(defn ellipsize
  "Returns the first three words in s followed by ..."
  [s]
  (let [[w1 w2 w3] (str/split s #"\s+")]
    (str/join " " [w1 w2 w3 "..."])))

(defn print-seq
  [s]
  (when (seq s)
    (prn (first s))
    (recur (rest s))))

(defn guys-whole-name ["Guy" "Lewis" "Steele"])

(let [[f-name m-name l-name] guys-whole-name]
  (str l-name ", " f-name " " m-name))
