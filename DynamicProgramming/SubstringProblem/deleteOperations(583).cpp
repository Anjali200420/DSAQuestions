class Solution {
private:
    int fun(int ind1, int ind2, string &word1, string &word2, vector<vector<int>> &dp){
        if(ind1 < 0 || ind2 < 0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(word1[ind1] == word2[ind2]){
            return dp[ind1][ind2] = 1 + fun(ind1-1, ind2-1, word1, word2, dp);
        }

        return dp[ind1][ind2] = max(fun(ind1-1, ind2, word1, word2, dp), fun(ind1, ind2-1, word1, word2, dp));
    }

public:
    // int minDistance(string word1, string word2) {
    //     int n1 = word1.length();
    //     int n2 = word2.length();

    //     vector<vector<int>> dp(n1, vector<int>(n2, -1));
    //     int lcs = fun(n1-1, n2-1, word1, word2, dp);

    //     return n1 + n2 - 2*lcs;
    // }

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        vector<int> prev0(n2+1, 0);
        
        for(int ind1 = 1; ind1 <= n1; ind1++){
            vector<int> prev1(n2+1, 0);
            for(int ind2 = 1; ind2 <= n2; ind2++){
                if(word1[ind1-1] == word2[ind2-1]){
                    prev1[ind2] = 1 + prev0[ind2-1];
                }
                else{
                    prev1[ind2] = max(prev0[ind2], prev1[ind2-1]);
                }
            }
            prev0 = prev1;
        }

        return n1 + n2 - 2*prev0[n2];
    }
};