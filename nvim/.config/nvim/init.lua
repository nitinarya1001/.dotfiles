local vim = vim
local Plug = vim.fn['plug#']

vim.call('plug#begin')

Plug('sainnhe/everforest')
Plug('vim-airline/vim-airline')
Plug('ryanoasis/vim-devicons')
Plug('windwp/nvim-autopairs')
Plug('lukas-reineke/indent-blankline.nvim')
Plug('lewis6991/gitsigns.nvim')
Plug('tpope/vim-fugitive')
Plug('numToStr/Comment.nvim')

Plug('nvim-lua/plenary.nvim')
Plug('nvim-telescope/telescope.nvim', { ['branch'] = '0.1.x' })
Plug('mbbill/undotree')

Plug('nvim-treesitter/nvim-treesitter', { ['do'] = ':TSUpdate' })
Plug('nvim-treesitter/playground')

Plug('neovim/nvim-lspconfig')
Plug('mason-org/mason.nvim')
Plug('mason-org/mason-lspconfig.nvim')

Plug('L3MON4D3/LuaSnip', { ['tag'] = 'v2.*', ['do'] = 'make install_jsregexp' })
Plug('rafamadriz/friendly-snippets')
Plug('Saghen/blink.cmp')

vim.call('plug#end')

require("set")
require("map")

---------------------------------------------------------
--                    airline                          --
---------------------------------------------------------
vim.cmd [[ let g:airline_theme = 'everforest' ]]

---------------------------------------------------------
--                   autopairs                         --
---------------------------------------------------------
require("nvim-autopairs").setup {}

---------------------------------------------------------
--                 indent-lines                        --
---------------------------------------------------------
local highlight = {
    "RainbowOrange",
}
local hooks = require "ibl.hooks"
hooks.register(hooks.type.HIGHLIGHT_SETUP, function()
    vim.api.nvim_set_hl(0, "RainbowOrange", { fg = "#D19A66" })
end)

vim.g.rainbow_delimiters = { highlight = highlight }
require("ibl").setup { scope = { highlight = highlight } }

hooks.register(hooks.type.SCOPE_HIGHLIGHT, hooks.builtin.scope_highlight_from_extmark)

---------------------------------------------------------
--                     git status                      --
---------------------------------------------------------
vim.keymap.set('n', '<leader>gs', vim.cmd.Git)

---------------------------------------------------------
--                 Comment shortcut                    --
---------------------------------------------------------
require('Comment').setup()

---------------------------------------------------------
--                     telescope                       --
---------------------------------------------------------
local builtin = require('telescope.builtin')
vim.keymap.set('n', '<leader>ff', builtin.find_files, { desc = 'Telescope find files' })
vim.keymap.set('n', '<leader>fg', builtin.live_grep, { desc = 'Telescope live grep' })
vim.keymap.set('n', '<leader>fb', builtin.buffers, { desc = 'Telescope buffers' })
vim.keymap.set('n', '<leader>fh', builtin.help_tags, { desc = 'Telescope help tags' })

---------------------------------------------------------
--                    Tree-sitter                      --
---------------------------------------------------------
require 'nvim-treesitter.configs'.setup ({
    -- A list of parser names, or "all" (the listed parsers MUST always be installed)
    ensure_installed = { "c", "lua", "javascript" },

    -- Install parsers synchronously (only applied to `ensure_installed`)
    sync_install = false,

    -- Automatically install missing parsers when entering buffer
    -- Recommendation: set to false if you don't have `tree-sitter` CLI installed locally
    auto_install = true,

    highlight = {
        enable = true,

        -- Setting this to true will run `:h syntax` and tree-sitter at the same time.
        -- Set this to `true` if you depend on 'syntax' being enabled (like for indentation).
        -- Using this option may slow down your editor, and you may see some duplicate highlights.
        -- Instead of true it can also be a list of languages
        additional_vim_regex_highlighting = false,
    },
})

---------------------------------------------------------
--                 Undo-tree bind                      --
---------------------------------------------------------
vim.keymap.set('n', '<leader>u', vim.cmd.UndotreeToggle)

---------------------------------------------------------
--                     MASON                           --
---------------------------------------------------------
require("mason").setup()

---------------------------------------------------------
--                MASON-LSP-config                     --
---------------------------------------------------------
require("mason-lspconfig").setup()

---------------------------------------------------------
--                LUA lsp config                       --
---------------------------------------------------------
vim.lsp.config("lua_ls", {
    settings = {
        Lua = {
            runtime = {
                version = "LuaJIT",
            },
            diagnostics = {
                globals = {
                    "vim",
                    "require",
                },
            },
            workspace = {
                library = vim.api.nvim_get_runtime_file("", true),
            },
            telemetry = {
                enable = false,
            },
        },
    },
})

---------------------------------------------------------
--            Snippets-and-auto-completion             --
---------------------------------------------------------
require("luasnip.loaders.from_vscode").lazy_load()
require("blink.cmp").setup({
    signature = { enabled = true },
    completion = {
        documentation = { auto_show = true, auto_show_delay_ms = 500 },
        menu = {
            auto_show = true,
            draw = {
                treesitter = { "lsp" },
                columns = { { "kind_icon", "label", "label_description", gap = 1 }, { "kind" } },
            },
        },
    },
    fuzzy = {
        implementation = "lua"
    },
    keymap = {
        preset = "default",
        ["<CR>"] = { "accept", "fallback" },
        ["<C-b>"] = { "scroll_documentation_up", "fallback" },
        ["<C-f>"] = { "scroll_documentation_down", "fallback" },
        ["<Tab>"] = { "select_next", "snippet_forward", "fallback" },
        ["<S-Tab>"] = { "select_prev", "snippet_backward", "fallback" },
    },
})
