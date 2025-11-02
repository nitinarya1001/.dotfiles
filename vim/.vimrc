call plug#begin()

Plug 'sainnhe/everforest'

Plug 'junegunn/fzf'
Plug 'junegunn/fzf.vim'

call plug#end()

"general
set nocompatible
filetype plugin indent on
set expandtab
set shiftwidth=4
set softtabstop=4
set tabstop=4
set number
set relativenumber
set smartindent
set showmatch
set backspace=indent,eol,start
syntax on

"colorscheme
set termguicolors
set background=dark
let g:everforest_background = 'soft'
let g:everforest_better_performance = 1
colorscheme everforest
highlight Normal None

"cursorline
set cursorline
highlight CursorLineNr guifg=#FFA500 

" netrw appearance
let g:netrw_banner=0
let g:netrw_liststyle=3
let g:netrw_showhide=1
let g:netrw_winsize=20

"undo history
if version >= 703
	set undodir=~/.vim/backup
	set undofile
	set undoreload=10000
endif

"search settings
set incsearch
set hlsearch
set ignorecase

"statusline
set laststatus=2

"keybindings

" Set leader key
let mapleader = " "

" Open netrw with <leader>cd
nnoremap <leader>cd :Ex<CR>

" FZF keymaps

" Files
nnoremap <leader>ff :Files<CR>
nnoremap <leader>fo :History<CR>
nnoremap <leader>fb :Buffers<CR>
nnoremap <leader>fq :CList<CR>    " For quickfix list
nnoremap <leader>fh :Helptags<CR>

" Grep current string
nnoremap <leader>fs :Rg <C-r><C-w><CR>

" Grep input string (fzf prompt)
nnoremap <leader>fg :Rg<Space>

" Grep for current file name (without extension)
nnoremap <leader>fc :execute 'Rg ' . expand('%:t:r')<CR>

" Find files in your Vim config
nnoremap <leader>fi :Files ~/.vim<CR>
