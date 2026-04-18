class Solution {
private:
    int fun(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        if(ind2 < 0) return 1;
        if(ind1 < 0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = fun(ind1-1, ind2-1, s1, s2, dp) + fun(ind1-1, ind2, s1, s2, dp);
        }

        return dp[ind1][ind2] = fun(ind1-1, ind2, s1, s2, dp);
    }

public:
    // int numDistinct(string s, string t) {
    //     int n1 = s.length();
    //     int n2 = t.length();

    //     vector<vector<int>> dp(n1, vector<int>(n2, -1));
    //     return fun(n1-1, n2-1, s, t, dp);
    // }

    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        vector<double> prev0(n2+1, 0);
        prev0[0] = 1;
    
        for(int ind1 = 1; ind1 <= n1; ind1++){
            vector<double> prev1(n2+1, 0);
            prev1[0] = 1;
            for(int ind2 = 1; ind2 <= n2; ind2++){
                if(s[ind1-1] == t[ind2-1]){
                    prev1[ind2] = prev0[ind2-1] + prev0[ind2];
                }
                else{
                    prev1[ind2] = prev0[ind2];
                }
            }
            prev0 = prev1;
        }

        return (int)prev0[n2];
    }
};