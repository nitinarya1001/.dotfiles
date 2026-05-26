-- COLORS
vim.opt.termguicolors = true
vim.cmd([[let g:everforest_better_performance = 1]])
vim.cmd.colorscheme("everforest")
vim.api.nvim_set_hl(0, "Normal", { bg = "#0D1215" })
vim.api.nvim_set_hl(0, "NormalNC", { bg = "#0C0104" })
vim.api.nvim_set_hl(0, "CursorLineNr", { fg = "#FFA500", bold = true })
