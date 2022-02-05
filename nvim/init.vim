"設定
set tabstop=4
set shiftwidth=4
set smartindent
set autoindent

"キー割当
inoremap s:: std::
noremap <C-_> 0i//<ESC> 

"PLUGIN
"=== dein script ===
if &compatible
  set nocompatible
endif
" Add the dein installation directory into runtimepath
set runtimepath+=~/.cache/dein/repos/github.com/Shougo/dein.vim

if dein#load_state('~/.cache/dein')
  call dein#begin('~/.cache/dein')

  call dein#add('~/.cache/dein/repos/github.com/Shougo/dein.vim')
  call dein#add('Shougo/deoplete.nvim')
  if !has('nvim')
    call dein#add('roxma/nvim-yarp')
    call dein#add('roxma/vim-hug-neovim-rpc')
  endif
  
  " toml files
  call dein#load_toml('~/.config/nvim/dein.toml', {'lazy': 0})
  call dein#load_toml('~/.config/nvim/dein_lazy.toml', {'lazy': 1}) 

  call dein#load_toml('~/.config/nvim/cpp.toml', {'lazy': 0})
  call dein#load_toml('~/.config/nvim/rust.toml', {'lazy': 0})

  call dein#end()
  call dein#save_state()
endif

  if dein#check_install()
	call dein#install()
  endif

filetype plugin indent on
syntax enable
