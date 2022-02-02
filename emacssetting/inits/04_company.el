(use-package company
  :config
  (global-company-mode t)
  (global-set-key (kbd "<C-tab>") 'company-complete)
  (bind-keys :map company-active-map
             ("C-n" . company-select-next)
             ("C-p" . company-select-previous))
  (bind-keys :map company-search-map
             ("C-n" . company-selecct-next)
             ("C-p" . company-select-previous))
  (bind-keys :map company-active-map
             ("<tab>" . company-complete-selection)))

(use-package company-lsp :commands company-lsp)
