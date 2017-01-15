(ns learn.core-test
  (:require [clojure.test :refer :all]
            [learn.core :refer :all]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 1 1))))

(deftest fib-test
  (testing "Fibonacci sequence"
    (is (= 1 (fib 1)))
    (is (= 2 (fib 2)))
    (is (= 3 (fib 3)))
    (is (= 5 (fib 4)))
    (is (= 8 (fib 6)))
    (is (= 13 (fib 7)))
    (is (= 21 (fib 8)))
    (is (= 34 (fib 9)))))

