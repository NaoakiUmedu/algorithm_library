(setq default-tab-width 4)
(setq initial-frame-alist
	  (append (list
			   '(width . 160)
			   '(height . 40)
			   '(top 0)
			   '(left 0)
			   )
			  initial-frame-alist))
(setq default-frame-alist initial-frame-alist)
(prefer-coding-system 'utf-8)

(require 'package)

(add-to-list 'package-archives '("melpa" . "http://melpa.org/packages/") t)
(add-to-list 'package-archives '("org" . "https://orgmode.org/elpa/") t)
(add-to-list 'package-archives '("gnu" . "https://elpa.gnu.org/packages/") t)

(package-initialize)
