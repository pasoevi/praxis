#! /usr/bin/env racket
#lang racket

(require racket/block)

(define author (make-parameter ""))

(define (backup! file [suffix ".bak"])
  (let ([backup-fname (string-append (path->string file) suffix)])
    (if (file-exists? backup-fname)
	(printf "File already exists: ~s\n" file)
	(copy-file file backup-fname))))

(define (add-notice! file [notice "notice.txt"] [backup-suffix ".bak"])
  (let ([backup-fname (string-append (path->string file) backup-suffix)])
    (call-with-input-file notice
      (lambda (notice-in) (call-with-input-file backup-fname
			    (lambda (in) (call-with-output-file file
					   (lambda (out) (block
							  (write-to-file (file->string notice-in) out)
							  (write-to-file (file->string in) out)
							  )))))))))
				    
				    

;; Finds Racket sources in all subdirs and add copyright notices to them
;; in the beginning
(define (add-notice-dir! directory [notice "notice.txt"])
  (for ([path directory]
	#:when (regexp-match? #rx"[.]rkt$" path))
       (block
       (backup! path)
       (delete-file path)
       (add-notice! path))))

(add-notice-dir! (in-directory))

(provide backup!
	 add-notice!
	 add-notice-dir!)
