(def visitors (atom #{}))
(defn hello
  "Writes hello message to out. Calls you by
  by username. Knows if you have been here before."
  [username]
  (swap! visitors conj username)
  (str "Hello, " username))

(if (= 1 (/ 2 2))
  (prn "YES!"))
(prn (hello "Sergi"))
