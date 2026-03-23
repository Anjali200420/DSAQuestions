class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> diff(n, vector<int>(m, -1));

        pq.push({0, {0, 0}});
        diff[0][0] = 0;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!pq.empty()){
            int dif = pq.top().first;

            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isValid(newRow, newCol, heights)){
                    int curDiff = max(dif, abs(heights[newRow][newCol] - heights[row][col]));

                    if(diff[newRow][newCol] == -1 || curDiff < diff[newRow][newCol]){
                        diff[newRow][newCol] = curDiff;
                        pq.push({curDiff, {newRow, newCol}});
                    }
                }
            }
        }

        return diff[n-1][m-1];
    }
};