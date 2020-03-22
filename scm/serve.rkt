#lang racket
(require net/url)

(string->url "http://en.wikipedia.org/wiki/Main_Page")

(define kat (string->url "file:///home/sergi/org/journal.org"))
(get-pure-port kat)
(read (get-pure-port kat))
(read (get-pure-port kat))
(read (get-pure-port kat))

(read (get-pure-port kat))

