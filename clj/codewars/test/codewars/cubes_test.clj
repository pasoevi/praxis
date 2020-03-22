(ns codewars.cubes-test
  (:require [clojure.test :refer :all]
            [codewars.cubes :refer :all]))


(deftest a-test1
  (testing "test1"
    (is (= (find-nb 4183059834009) 2022))))
(deftest a-test2
  (testing "test2"
    (is (= (find-nb 24723578342962) -1))))
(deftest a-test3
  (testing "test3"
    (is (= (find-nb 135440716410000) 4824))))
(deftest a-test4
  (testing "test4"
    (is (= (find-nb 40539911473216) 3568))))
