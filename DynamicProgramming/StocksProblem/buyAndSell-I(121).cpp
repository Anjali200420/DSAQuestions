class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int ans = 0;
        int minElement = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] <= minElement){
                minElement = prices[i];
                continue;
            }

            ans = max(ans, prices[i] - minElement);
        }

        return ans;
    }
};