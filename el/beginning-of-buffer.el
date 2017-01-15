(defun simplified-end-of-buffer ()
  "Move the point to the end of the buffer;
leave the mark at the previous position"
  (interactive)
  (push-mark)
  (goto-char (point-max)))


