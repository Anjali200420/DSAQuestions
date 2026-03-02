class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vec(n);

        // Finding the trailing zeroes
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = n; --j >= 0 && !grid[i][j]; )count++;

            vec[i] = count;
        }

        // Check no of swaps required greedily
        int ans = 0;
        for(int i = 0; i < n; i++){
            int k = i;
            int req = (n - 1 - i);

            while(k < n && vec[k] < req) k++;
            if(k == n) return -1;

            ans += (k-i);

            while(k > i){
                vec[k] = vec[k-1];
                k--;
            }
        }

        return ans;
    }
};