vim.g.base46_cache = vim.fn.stdpath "data" .. "/base46/"
vim.g.mapleader = " "
vim.lsp.inline_completion.enable(true)
-- bootstrap lazy and all plugins
local lazypath = vim.fn.stdpath "data" .. "/lazy/lazy.nvim"

if not vim.uv.fs_stat(lazypath) then
  local repo = "https://github.com/folke/lazy.nvim.git"
  vim.fn.system { "git", "clone", "--filter=blob:none", repo, "--branch=stable", lazypath }
end

vim.opt.rtp:prepend(lazypath)

local lazy_config = require "configs.lazy"

-- load plugins
require("lazy").setup({
  {
    "NvChad/NvChad",
    lazy = false,
    branch = "v2.5",
    import = "nvchad.plugins",
  },

  { import = "plugins" },
}, lazy_config)

-- load theme
dofile(vim.g.base46_cache .. "defaults")
dofile(vim.g.base46_cache .. "statusline")
require "options"
require "autocmds"

vim.schedule(function()
  vim.opt.clipboard = "unnamedplus"
  require "mappings"
    -- DIRECT C++ COMPILER OVERRIDE
  vim.keymap.set({"n", "i"}, "<leader>rr", function()
    vim.cmd("w") 
    local file = vim.fn.expand("%")
    local output = vim.fn.expand("%:r")
    vim.cmd(string.format("split | terminal g++ -std=c++20 -O2 %s -o %s && ./%s", file, output, output))
    vim.cmd("startinsert")
  end, { desc = "Compile and Run C++" })
  vim.keymap.set("i", "<C-CR>", function()
  if vim.lsp.inline_completion.get() then
    vim.lsp.inline_completion.accept()
  else
    -- if no ghost text exists, just act like a normal enter key
    vim.api.nvim_feedkeys(vim.api.nvim_replace_termcodes("<C-CR>", true, true, true), "n", true)
  end
end, { desc = "Accept Copilot Inline Completion" })

  -- Lowercase entire buffer and jump back to original cursor position
vim.keymap.set("n", "<leader>kl", "ggguG<C-o>", { noremap = true, desc = "Lowercase entire file" })
  -- DSA Git Automation
vim.keymap.set("n", "<leader>gp", function()
  vim.cmd("w") -- save the file first
  local file = vim.fn.expand("%") -- get relative file path
  
  -- open terminal split and run the push script with the current file
  vim.cmd(string.format("split | terminal ../scripts/push.sh %s", file))
  
  -- drop into insert mode to type the commit message
  vim.cmd("startinsert")
end, { desc = "Push DSA to GitHub" })
end)
vim.keymap.set('n', '<leader>cpp', function()
  -- 1. extract the current filename without the .cpp extension
  local filename = vim.fn.expand('%:t:r')
  
  -- 2. parse the function name (strips everything before and including the first underscore)
  local func_name = string.match(filename, "^%d+_(.+)$")
  
  -- fallback just in case you create a file without the "05_" number prefix
  if not func_name then
    func_name = filename
  end

  -- 3. construct the boilerplate matrix
  local template = {
    "#include <bits/stdc++.h>",
    "using namespace std;",
    "",
    "class Solution {",
    "public:",
    "  int " .. func_name .. "(int n) {",
    "    int res;",
    "     ", -- line 8: this is where your cursor will land
    "     ",
    "     ",
    "    return res;",
    "  }",
    "};",
    "",
    "int main() {",
    "  Solution obj;",
    "  int n = 5;",
    "  cout << obj." .. func_name .. "(n);",
    "",
    "  return 0;",
    "}"
  }

  -- 4. inject the template directly into the buffer, replacing any existing empty lines
  vim.api.nvim_buf_set_lines(0, 0, -1, false, template)

  -- 5. instantly teleport the cursor inside the function block (line 7, column 4)
  vim.api.nvim_win_set_cursor(0, {8, 5})
  
  -- 6. drop into insert mode so you can immediately start typing the logic
  vim.cmd("startinsert")
  
end, { desc = "Inject C++ DSA Boilerplate" })

vim.keymap.set('n', '<leader>cpa', function()
  -- 1. extract the current filename without the .cpp extension
  local filename = vim.fn.expand('%:t:r')
  
  -- 2. parse the function name (strips everything before and including the first underscore)
  local func_name = string.match(filename, "^%d+_(.+)$")
  
  -- fallback just in case you create a file without the "05_" number prefix
  if not func_name then
    func_name = filename
  end

  -- 3. construct the boilerplate matrix
  local template = {
    "#include <bits/stdc++.h>",
    "using namespace std;",
    "",
    "class Solution {",
    "public:",
    "  vector<int> " .. func_name .. "(vector<int>& nums) {",
    "    vector<int> res;",
    "     ", -- line 8: this is where your cursor will land
    "     ",
    "     ",
    "    return res;",
    "  }",
    "};",
    "",
    "int main() {",
    "  Solution obj;",
    "  vector<int> nums = {5, 4, 3, 2, 1};",
    "  vector<int> res = obj." .. func_name .. "(nums);",
    "",
    "  for (auto i : res) {",
    "    cout << i << \" \";",
    "  }",
    "  cout << endl;",
    "",
    "  return 0;",
    "}"
  }

  -- 4. inject the template directly into the buffer, replacing any existing empty lines
  vim.api.nvim_buf_set_lines(0, 0, -1, false, template)

  -- 5. instantly teleport the cursor inside the function block (line 7, column 4)
  vim.api.nvim_win_set_cursor(0, {8, 5})
  
  -- 6. drop into insert mode so you can immediately start typing the logic
  vim.cmd("startinsert")
  
end, { desc = "Inject C++ DSA Boilerplate" })

