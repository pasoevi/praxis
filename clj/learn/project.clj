(defproject learn "0.1.0-SNAPSHOT"
  :description "Learning Clojure"
  :url "http://www.essayer.info"
  :license {:name "Eclipse Public License"
            :url "http://www.eclipse.org/legal/epl-v10.html"}
  :dependencies [[org.clojure/clojure "1.6.0"]]
  :main ^:skip-aot learn.core
  :target-path "target/%s"
  :profiles {:uberjar {:aot :all}:dev {:plugins [[cider/cider-nrepl "0.8.1"]]}})
