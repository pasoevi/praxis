(defun check-buffer
(interactive)
(if (get-buffer (read-buffer "Find buffer: "))
    (message "The buffer exists")
  (message "The buffer doesn't exist")))
