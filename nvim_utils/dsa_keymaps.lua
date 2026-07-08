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
    "#include <iostream>",
    "using namespace std;",
    "",
    "class Solution {",
    "public:",
    "  int " .. func_name .. "(int n) {",
    "    ", -- line 7: this is where your cursor will land
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
  vim.api.nvim_win_set_cursor(0, {7, 4})
  
  -- 6. drop into insert mode so you can immediately start typing the logic
  vim.cmd("startinsert")
  
end, { desc = "Inject C++ DSA Boilerplate" })
