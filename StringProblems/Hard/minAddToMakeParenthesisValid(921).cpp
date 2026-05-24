class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();

        int count = 0;
        int ans = 0;
        for(int ind = 0; ind < n; ind++){
            if(count == 0 && s[ind] == ')') ans++;
            else if(s[ind] == '(') count++;
            else if(s[ind] == ')') count--;
        }

        ans += count;
        return ans;
    }
};