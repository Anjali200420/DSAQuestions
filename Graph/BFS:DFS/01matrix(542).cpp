class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                }
            }
        }

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isValid(newRow, newCol, mat) && mat[newRow][newCol] == 1 && ans[newRow][newCol] == 0){
                    ans[newRow][newCol] = dis + 1;

                    q.push({{newRow, newCol}, dis+1});
                }
            }
        }

        return ans;
    }
};