class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        if(grid.size() == 1 && grid[0].size() == 1) return 0;

        int row = grid.size();
        int col = grid[0].size();

        vector<int> temp;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.begin(), temp.end());

        int n = temp.size();
        int el = temp[0];
        if(n % 2 != 0){
            int ind = n/2;
            el = temp[ind];
        }
        else{
            int ind1 = (n - 1) / 2;
            int ind2 = n / 2;

            if((temp[ind1] - temp[0]) > (temp[n-1] - temp[ind2])){
                el = temp[ind1];
            }
            else{
                el = temp[ind2];
            }
        }

        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(abs(grid[i][j] - el) % x != 0) return -1;
                ans += abs(grid[i][j] - el) / x;
            }
        }

        return ans;
    }
};