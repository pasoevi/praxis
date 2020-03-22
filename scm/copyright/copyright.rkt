#! /usr/bin/env racket
#lang racket

(require racket/block)

(define author (make-parameter ""))

(define (backup! file [suffix ".bak"])
  (let ([backup-fname (string-append (path->string file) suffix)])
    (if (file-exists? backup-fname)
	(printf "File already exists: ~s\n" file)
	(copy-file file backup-fname))))

(define (add-notice! file [notice "notice"] [backup-suffix ".bak"])
  (let ([backup-fname (string-append (path->string file) backup-suffix)])
    (display file)
    (display-to-file (file->string notice) file)
    (display-to-file "\n" file #:exists 'append)
    (display-to-file (file->string backup-fname) file  #:exists 'append)))
				    
				    

;; Finds Racket sources in all subdirs and add copyright notices to them
;; in the beginning
(define (add-notice-dir! directory [notice "notice"])
  (for ([path (in-directory)]
	#:when (regexp-match? #rx"[.]txt$" path))
       (block
       (backup! path)
       (delete-file path)
       (add-notice! path))))

(add-notice-dir! (current-directory))

(provide backup!
	 add-notice!
	 add-notice-dir!)
