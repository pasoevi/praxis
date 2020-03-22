(ns codewars.squaresums-test
  (:require [clojure.test :refer :all]
            [codewars.squaresums :refer :all]))

(deftest a-test1
  (testing "test1"
    (is (= (list-squared 1 250) [[1, 1], [42, 2500], [246, 84100]]))))
(deftest a-test2
  (testing "test2"
    (is (= (list-squared 42 250) [[42, 2500], [246, 84100]]))))
(deftest a-test3
  (testing "test3"
    (is (= (list-squared 250 500) [[287, 84100]]))))

(deftest a-test10
  (testing "Sergi Test"
    (is (= (list-squared 41 43) [[42, 2500]]))))
