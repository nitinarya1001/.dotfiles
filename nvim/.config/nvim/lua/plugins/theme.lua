-- ================================================================================================
-- TITLE : melange-nvim
-- ABOUT : A subtle, warm colorscheme for Neovim inspired by Sublime Text's Melange theme.
-- LINKS :
--   > github : https://github.com/savq/melange-nvim
-- ================================================================================================

return {
	"sainnhe/everforest",
	lazy = false,
	priority = 1000,
	config = function()
		vim.cmd("colorscheme everforest")
                vim.api.nvim_set_hl(0, "Normal", { bg = "none" })
                vim.api.nvim_set_hl(0, "NormalNC", { bg = "none" })
                vim.api.nvim_set_hl(0, "EndOfBuffer", { bg = "none" })
                vim.api.nvim_set_hl(0, 'CursorLineNr', { fg = 'orange' })

	end,
}
