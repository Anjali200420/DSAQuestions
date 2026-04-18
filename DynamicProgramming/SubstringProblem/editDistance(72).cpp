class Solution {
private:
    long long fun(int ind1, int ind2, string &word1, string &word2, vector<vector<int>> &dp){
        if(ind2 < 0) return ind1+1;
        if(ind1 < 0) return ind2+1;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(word1[ind1] == word2[ind2]){
            return dp[ind1][ind2] = fun(ind1-1, ind2-1, word1, word2, dp);
        }

        return dp[ind1][ind2] = 1 + min(fun(ind1, ind2-1, word1, word2, dp), min(fun(ind1-1, ind2, word1, word2, dp), fun(ind1-1, ind2-1, word1, word2, dp)));

    }

public:
    // int minDistance(string word1, string word2) {
    //     int n1 = word1.length();
    //     int n2 = word2.length();

    //     if(n1 == 0) return n2;
        
    //     vector<vector<int>> dp(n1, vector<int>(n2, -1));
    //     return fun(n1-1, n2-1, word1, word2, dp);
    // }

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        if(n1 == 0) return n2;
        
        vector<int> prev0(n2+1, 0);

        for(int ind = 1; ind <= n2; ind++){
            prev0[ind] = ind;
        }

        for(int ind1 = 1; ind1 <= n1; ind1++){
            vector<int> prev1(n2+1, 0);
            prev1[0] = ind1;
            for(int ind2 = 1; ind2 <= n2; ind2++){
                if(word1[ind1-1] == word2[ind2-1]){
                    prev1[ind2] = prev0[ind2-1];
                }
                else{
                    prev1[ind2] = 1 + min(prev1[ind2-1], min(prev0[ind2], prev0[ind2-1]));
                }
            }
            prev0 = prev1;
        }

        return prev0[n2];
    }
};