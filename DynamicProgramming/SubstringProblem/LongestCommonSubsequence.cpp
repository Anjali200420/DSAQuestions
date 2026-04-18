class Solution {
  private:
    int fun(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = 1 + fun(ind1-1, ind2-1, s1, s2, dp);
        }
        
        return dp[ind1][ind2] = max(fun(ind1-1, ind2, s1, s2, dp), fun(ind1, ind2-1, s1, s2, dp));
    }
    
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n1 = s1.length();
        int n2 = s2.length();
        
        vector<int> prev0(n2 + 1, 0);
        
        for(int ind1 = 1; ind1 <= n1; ind1++){
            vector<int> prev1(n2 + 1);
            for(int ind2 = 1; ind2 <= n2; ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                    prev1[ind2] = 1 + prev0[ind2-1];
                }
                else{
                    prev1[ind2] = max(prev0[ind2], prev1[ind2-1]);
                }
            }
            prev0 = prev1;
        }
        
        return prev0[n2];
    }
};
