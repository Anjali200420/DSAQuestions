class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int ind1 = 1; ind1 <= n1; ind1++){
            for(int ind2 = 1; ind2 <= n2; ind2++){
                if(str1[ind1-1] == str2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
                }
            }
        }

        string ans = "";

        int row = n1, col = n2;
        while(row > 0 && col > 0){
            if(str1[row-1] == str2[col-1]){
                ans += str1[row-1];
                row--; col--;
            }
            else if(dp[row-1][col] > dp[row][col-1]){
                ans += str1[row-1];
                row--;
            }
            else{
                ans += str2[col-1];
                col--;
            }
        }

        while(row > 0){
            ans += str1[row-1];
            row--;
        }

        while(col > 0){
            ans += str2[col-1];
            col--;
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};