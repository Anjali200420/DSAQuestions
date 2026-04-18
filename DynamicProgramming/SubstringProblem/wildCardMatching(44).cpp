class Solution {
private:
    int fun(int ind1, int ind2, string &s, string &p, vector<vector<int>> &dp){
        if(ind1 < 0 && ind2 < 0) return 1;
        if(ind1 >= 0 && ind2 < 0) return 0;

        if(ind1 < 0 && ind2 >= 0){
            for(int ind = 0; ind <= ind2; ind++){
                if(p[ind] != '*') return 0;
            }

            return 1;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(s[ind1] == p[ind2] || p[ind2] == '?') return dp[ind1][ind2] = fun(ind1-1, ind2-1, s, p, dp);
        
        if(p[ind2] == '*'){
            return dp[ind1][ind2] = (fun(ind1-1, ind2, s, p, dp) || fun(ind1, ind2-1, s, p, dp));
        }

        return dp[ind1][ind2] = 0;
    }

public:
    // bool isMatch(string s, string p) {
    //     int n1 = s.length();
    //     int n2 = p.length();

    //     vector<vector<int>> dp(n1, vector<int>(n2, -1));
    //     return fun(n1-1, n2-1, s, p, dp);
    // }

    bool isMatch(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();

        vector<bool> prev0(n2+1, false);
        
        prev0[0] = true;
        for(int ind = 1; ind <= n2; ind++){
            if(p[ind-1] != '*') break;
            prev0[ind] = true;
        }

        for(int ind1 = 1; ind1 <= n1; ind1++){
            vector<bool> prev1(n2+1, false);
            for(int ind2 = 1; ind2 <= n2; ind2++){
                if(s[ind1-1] == p[ind2-1] || p[ind2 - 1] == '?'){
                    prev1[ind2] = prev0[ind2-1];
                }
                else if(p[ind2-1] == '*'){
                    prev1[ind2] = prev0[ind2] || prev1[ind2-1];
                }
            }
            prev0 = prev1;
        }

        return prev0[n2];
    }
};