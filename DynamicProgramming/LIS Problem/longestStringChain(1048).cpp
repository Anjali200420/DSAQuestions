class Solution {
private:
    bool isSubsequence(string word1, string word2){
        int i = 0, j = 0;
        while(i < word1.length() && j < word2.length()){
            if(word1[i] == word2[j]) i++;
            j++;
        }

        if(i == word1.length()) return true;
        return false;
    }

    int fun(int ind, int prev_ind, vector<string>& words, vector<vector<int>>& dp){
        if(ind == words.size()) return 0;

        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        int take = 0;
        if(prev_ind == -1 || (words[ind].length() == 1 + words[prev_ind].length() && isSubsequence(words[prev_ind], words[ind]))){
            take = 1 + fun(ind+1, ind, words, dp);
        }
        
        int notTake = fun(ind+1, prev_ind, words, dp);

        return dp[ind][prev_ind+1] = max(take, notTake);
    }
public:
    // int longestStrChain(vector<string>& words) {
    //     int n = words.size();

    //     sort(words.begin(), words.end(), [](const string &a, const string &b){
    //         return a.length() < b.length();
    //     });

    //     vector<vector<int>> dp(n, vector<int>(n+1, -1));
    //     return fun(0, -1, words, dp);
    // }

    // int longestStrChain(vector<string>& words) {
    //     int n = words.size();

    //     sort(words.begin(), words.end(), [](const string &a, const string &b){
    //         return a.length() < b.length();
    //     });

    //     vector<int> prev0(n+1, 0);
        
    //     for(int ind1 = n-1; ind1 >= 0; ind1--){
    //         vector<int> prev1(n+1, 0);
    //         for(int ind2 = ind1-1; ind2 >= -1 ; ind2--){
    //             int take = 0;
    //             if(ind2 == -1 || (words[ind1].length() == 1 + words[ind2].length() && isSubsequence(words[ind2], words[ind1]))){
    //                 take = 1 + prev0[ind1+1];
    //             }

    //             int notTake = prev0[ind2+1];

    //             prev1[ind2+1] = max(take, notTake);
    //         }
    //         prev0 = prev1;
    //     }

    //     return prev0[0];
    // }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.length() < b.length();
        });

        vector<int> hash(n, 1);

        int ans = 1;
        for(int ind1 = 1; ind1 < n; ind1++){
            for(int ind2 = 0; ind2 < ind1; ind2++){
                if(words[ind1].length() == 1 + words[ind2].length() && isSubsequence(words[ind2], words[ind1])){
                    hash[ind1] = max(hash[ind1], 1 + hash[ind2]);
                }
            }
            ans = max(ans, hash[ind1]);
        }

        return ans;
    }
};