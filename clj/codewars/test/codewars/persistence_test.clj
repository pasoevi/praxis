(ns codewars.persistence-test
  (:require [clojure.test :refer :all]
            [codewars.persistence :refer :all]))

(deftest count-digits-test
  (testing "count-digits."
    (is (= (count-digits 1) 1))
    (is (= (count-digits 2) 1))
    (is (= (count-digits 100) 3))
    (is (= (count-digits 900) 3))
    (is (= (count-digits 1000) 4))
    (is (= (count-digits 1110) 4))
    (is (= (count-digits 10000) 5))
    (is (= (count-digits 198910) 6))
    (is (= (count-digits -198910) 6))
    (is (= (count-digits -1) 1))
    ))


(deftest initial-tests
  (testing "Initial Tests"
    (is (= (persistence 39) 3))
    (is (= (persistence 4) 0))
    (is (= (persistence 25) 2))
    (is (= (persistence 999) 4))))
