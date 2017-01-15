#lang web-server/insta

(define (start request)
  (response/xexpr
   '(html 
     (head (title "My Journal"))
     (body (h1 "Under construction")))))

(struct post (title body))

(define blog '(post "First Post" "First things first"))
blog