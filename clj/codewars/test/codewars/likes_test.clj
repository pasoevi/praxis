(ns codewars.likes-test
  (:require [clojure.test :refer :all]
            [codewars.likes :refer :all]))

(deftest likes-test
  (testing "likes."
    (is (= (likes []) "no one likes this"))
    (is (= (likes ["Peter"]) "Peter likes this"))
    (is (= (likes ["Jackob" "Alex"]) "Jackob and Alex like this"))
    (is (= (likes ["Max" "John" "Mark"]) "Max, John and Mark like this"))
    (is (= (likes ["Alex" "Jacob" "Mark" "Max"]) "Alex, Jacob and 2 others like this"))))
