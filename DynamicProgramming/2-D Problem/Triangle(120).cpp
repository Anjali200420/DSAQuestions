class Solution {
private:
    int fun(int rowInd, int colInd, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(rowInd == triangle.size()-1) return triangle[rowInd][colInd];

        if(dp[rowInd][colInd] != INT_MAX) return dp[rowInd][colInd];
        int down = triangle[rowInd][colInd] + fun(rowInd+1, colInd, triangle, dp);
        int diagonal = triangle[rowInd][colInd] + fun(rowInd+1, colInd+1, triangle, dp); 

        return dp[rowInd][colInd] = min(down, diagonal);
    }

public:
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     int m = triangle[n-1].size();

    //     vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    //     return fun(0, 0, triangle, dp);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<int> prev0(m);
        
        for(int col = 0; col < m; col++){
            prev0[col] = triangle[n-1][col];
        }
        
        for(int i = n-2; i >= 0; i--){
            vector<int> prev1(m);
            for(int j = 0; j < triangle[i].size(); j++){
                int down = prev0[j];
                int diagonal = prev0[j+1];

                prev1[j] = triangle[i][j] + min(down, diagonal);
            }
            prev0 = prev1;
        }

        return prev0[0];
    }
};