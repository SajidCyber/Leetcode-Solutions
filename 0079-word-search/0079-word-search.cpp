class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        if (word.length() > m * n) return false;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        if (index == word.length()) {
            return true;
        }
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        
        char temp = board[r][c];
        board[r][c] = '#';
        
        bool found = dfs(board, word, r + 1, c, index + 1) || 
                     dfs(board, word, r - 1, c, index + 1) || 
                     dfs(board, word, r, c + 1, index + 1) || 
                     dfs(board, word, r, c - 1, index + 1);
        
        board[r][c] = temp;
        
        return found;
    }
};