class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // your code here
        int n1 = s1.length();
        int n2 = s2.length();
        
        vector<int> prev0(n2+1, 0);
        
        int ans = 0;
        for(int ind1 = 1; ind1 <= n1; ind1++){
            vector<int> prev1(n2+1, 0);
            for(int ind2 = 1; ind2 <= n2; ind2++){
                if(s1[ind1-1] == s2[ind2-1]){
                    prev1[ind2] = 1 + prev0[ind2-1];
                    ans = max(ans, prev1[ind2]);
                }
            }
            prev0 = prev1;
        }
        
        return ans;
    }
};