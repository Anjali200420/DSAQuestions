class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> horizontalPrefix(n);
        vector<long long> horizontalSuffix(n);

        long long prefixSum = 0, suffixSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                prefixSum += grid[i][j];
                suffixSum += grid[n-i-1][j];
            }

            horizontalPrefix[i] = prefixSum;
            horizontalSuffix[n-i-1] = suffixSum;
        }

        for(int i = 0; i < n-1; i++){
            if(horizontalPrefix[i] == horizontalSuffix[i+1]) return true;
        }

        vector<long long> verticalPrefix(m);
        vector<long long> verticalSuffix(m);

        prefixSum = 0, suffixSum = 0;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                prefixSum += grid[i][j];
                suffixSum += grid[i][m-j-1];
            }

            verticalPrefix[j] = prefixSum;
            verticalSuffix[m-j-1] = suffixSum;
        }

        for(int i = 0; i < m-1; i++){
            if(verticalPrefix[i] == verticalSuffix[i+1]) return true;
        }

        return false;
    }
};