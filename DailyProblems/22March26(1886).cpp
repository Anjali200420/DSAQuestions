class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();

        for(int rotation = 0; rotation < 4; rotation++){
            vector<vector<int>> temp = mat;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    temp[i][j]= mat[j][n-i-1];
                }
            }

            if(temp == target) return true;
            mat = temp;
        }
        

        return false;
    }
};