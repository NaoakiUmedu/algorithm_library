(use-package lsp-mode
  :hook ((c++-mode c-mode) . lsp)
  :commands lsp
  :config
  (setq lsp-prefer-flymake nil)
  :init
  (unbind-key "C-l")
  :bind
  (("C-l f" . lsp-format-buffer)
   ("C-l t" . lsp-goto-type-definition)
   ("C-l r" . lsp-rename)
   ("C-l <f5>" . lsp-restart-workspace))
  )

(use-package lsp-python-ms
  :ensure t
  :init
  (setq lsp-python-ms-auto-install-server t)
  (unbind-key "C-l")
  :bind
  (("C-l f" . lsp-format-buffer)
   ("C-l t" . lsp-goto-type-definition)
   ("C-l r" . lsp-rename)
   ("C-l <f5>" . lsp-restart-workspace))
  :hook (python-mode . (lambda ()
                         (require 'lsp-python-ms)
                         (lsp))))  ; or lsp-deferred

(use-package lsp-ui :commands lsp-ui-mode)
