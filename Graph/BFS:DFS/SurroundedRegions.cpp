class Solution {
private:
    bool isValid(int row, int col, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[row][col] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(isValid(newRow, newCol, board) && board[newRow][newCol] == 'O' && !vis[newRow][newCol]){
                dfs(newRow, newCol, vis, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') dfs(i, 0, vis, board);
            if(board[i][m-1] == 'O') dfs(i, m-1, vis, board);
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O') dfs(0, i, vis, board);
            if(board[n-1][i] == 'O') dfs(n-1, i, vis, board);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};