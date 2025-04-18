vim.g.mapleader = " "

local o = vim.o
local map = vim.keymap.set
local builtin = require('telescope.builtin')

o.nu = true
o.relativenumber = true
o.tabstop = 4
o.softtabstop = 4
o.shiftwidth = 4
o.expandtab = true
o.smartindent = true
o.wrap = false
o.hlsearch = false
o.incsearch = true
o.scrolloff = 8
o.sidescrolloff = 8
o.updatetime = 500
o.foldmethod = "indent"
o.foldlevel = 99
o.foldlevelstart = 1
o.foldenable = false
o.foldtext = ""

local runcpp = "!g++ -std=c++17 -DLOCAL -Wall -Wextra -Winvalid-pch -O2 -I . main.cpp -o main && ./main < input.txt > output.txt"

map("i", "{<cr>", "{<cr>}<esc>O")
map("i", "<C-c>", "<esc>")
map("n", "<leader>cc", "<cmd>%y+<cr>")
map("n", "<leader>cr", "<cmd>wa<bar>" .. runcpp .. "<cr>")
map("n", "<leader>cx", "gg\"_dG\"+P<cmd>wa<bar>" .. runcpp .. "<cr>")
map("n", "<leader>ca", "gg\"_dG")
map("n", "<leader>ci", "gg\"_dG<cmd>r ./templates/init.cpp<cr>kdd/solve<cr>j")
map("n", "<leader>ck", "gg\"_dG<cmd>r ./templates/kactl.cpp<cr>kdd/main<cr>3j")
map("n", "<leader>cp", "<cmd>w<bar>belowright vsplit<bar>wincmd l<bar>terminal python %<cr>i")
map("n", "<tab>", "<C-w>w")
map("v", "J", ":m '>+1<cr>gv=gv")
map("v", "K", ":m '<-2<cr>gv=gv")

vim.api.nvim_set_keymap("v", "<leader>cp", ":lua RunSelection()<CR>", { noremap = true, silent = true })

function RunSelection()
  -- Get the start and end of the visual selection
  local start_line = vim.fn.line("'<")
  local end_line = vim.fn.line("'>")
  -- Retrieve the selected lines
  local lines = vim.fn.getline(start_line, end_line)
  -- Create a temporary file with a .py extension
  local tmp_file = vim.fn.tempname() .. ".py"
  -- Write the selected lines to the temporary file
  vim.fn.writefile(lines, tmp_file)
  -- Open a vertical split terminal running Python with the temporary file
  vim.cmd("belowright vsplit | terminal python " .. tmp_file)
  -- Set the terminal to insert mode
  vim.cmd("startinsert")
end

map("i", '<Tab>', function()
  if require("copilot.suggestion").is_visible() then
    require("copilot.suggestion").accept()
  else
    vim.api.nvim_feedkeys(vim.api.nvim_replace_termcodes("<Tab>", true, false, true), "n", false)
  end
end, {
  silent = true,
})

map("n", "<leader>cex", function()
    local path = "/run/media/tsktsk"
    if vim.fn.isdirectory(path) == 1 then
        local items = vim.fn.readdir(path)
        if #items > 0 then
            local current_file = vim.fn.expand("%:p")
            local filename = vim.fn.fnamemodify(current_file, ":t")
            local full_path = path .. "/" .. items[1] .. "/" .. filename
            local success = vim.fn.writefile(vim.fn.readfile(current_file), full_path)
            if success == 0 then
                print("File copied successfully to " .. full_path)
            else
                print("Failed to copy file")
            end
        end
    end
end)

local function merge_files(path, depth)
    if depth > 5 then return end
    local content = vim.fn.readfile(path)
    local ret = ""
    for _, line in ipairs(content) do
        if line:find("#include") then
            local file = line:match("#include \"(.+)\"")
            if file then
                ret = ret .. merge_files(file, depth + 1)
            else
                ret = ret .. line .. "\n"
            end
        else
            ret = ret .. line .. "\n"
        end
    end
    return ret
end

map("n", "<leader>cl", function()
    local path = vim.fn.expand("%:p")
    local content = merge_files(path, 0)
    vim.fn.setreg("+", content)
end)


map('n', '<leader>ff', builtin.find_files, {})
map('n', '<leader>fg', builtin.live_grep, {})
map('n', '<leader>fb', builtin.buffers, {})
map('n', '<leader>fh', builtin.help_tags, {})

local lsp_zero = require('lsp-zero')

lsp_zero.on_attach(function(client, bufnr)
  -- see :help lsp-zero-keybindings
  -- to learn the available actions
  lsp_zero.default_keymaps({buffer = bufnr})
end)

require('mason').setup({})
require('mason-lspconfig').setup({
  ensure_installed = {'clangd', 'tailwindcss', 'jsonls' },
  handlers = {
    function(server_name)
      require('lspconfig')[server_name].setup({})
    end,
  },
})

require('telescope').setup{ 
  defaults = { 
    file_ignore_patterns = { 
      "node_modules" 
    }
  }
}

local cmp = require('cmp')
cmp.setup({
  mapping = cmp.mapping.preset.insert({
    -- confirm completion
    ['<CR>'] = cmp.mapping.confirm({select = true}),

    -- scroll up and down the documentation window
    ['<C-u>'] = cmp.mapping.scroll_docs(-4),
    ['<C-d>'] = cmp.mapping.scroll_docs(4),   
  }),
})
