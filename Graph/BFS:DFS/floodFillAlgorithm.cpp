class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

    void dfsTraversal(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int initColor, int color){
        ans[row][col] = color;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(isValid(newRow, newCol, image) && image[newRow][newCol] == initColor && ans[newRow][newCol] != color){
                dfsTraversal(newRow, newCol, ans, image, initColor, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];

        vector<vector<int>> ans = image;
        dfsTraversal(sr, sc, ans, image, initColor, color);

        return ans;
    }
};