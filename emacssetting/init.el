
;;;;; key bindings ;;;;;
;(define-key global-map (kbd "M-SPC") 'set-mark-command)

;;;;; macros ;;;;:
(add-hook 'before-save-hook 'delete-trailing-whitespace)

;; for first setting
;(require 'package)
;
;;; package-archivesを上書き
;(setq package-archives
;      '(("melpa" . "http://melpa.org/packages/")
;        ;; ("melpa-stable" . "https://stable.melpa.org/packages/")
;        ("org" . "http://orgmode.org/elpa/")
;        ("gnu" . "http://elpa.gnu.org/packages/")))
;
;;; 初期化
;(package-initialize)

;;;;;;
(require 'init-loader)
(init-loader-load "~/.emacs.d/inits")

(require 'use-package)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages
   '(racket-mode geiser-racket geiser rust-mode lsp-pyright lsp-python-ms company flycheck clang-format use-package lsp-ui lsp-mode init-loader))
 '(tab-width 4))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

;;;;; settings ;;;;;
(setq default-tab-width 4)
