(ns play.core-test
  (:require [clojure.test :refer :all]
            [play.peg :refer :all]))

(deftest tri-test
  (testing "tri* function returning triangular nambers"
    (is (= 1 (first (take 3 tri))))
    (is (= 6 (last (take 3 tri))))))


(deftest triangular?-test
  (testing "triangular? number"
    (is (= true (triangular? 1)))
    (is (= true (triangular? 3)))
    (is (= false (triangular? 4)))
    (is (= false (triangular? 5)))))

