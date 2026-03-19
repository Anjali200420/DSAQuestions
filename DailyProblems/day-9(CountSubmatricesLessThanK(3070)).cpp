class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if(grid[0][0] > k) return 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>& preSum = grid;

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(i == 0) continue;
                preSum[i][j] += preSum[i-1][j];
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j == 0) continue;
                preSum[i][j] += preSum[i][j-1];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(preSum[i][j] <= k) ans++;
            }
        }

        return ans;
    }
};