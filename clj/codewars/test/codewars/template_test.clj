(ns codewars.template-test
  (:require [clojure.test :refer :all]
            [codewars.template :refer :all]))

(deftest TemplateTest
  (is (= ((template "{{name}} likes {{interests}}") {:name "John" :interests "dogs"})
         "John likes dogs")))
