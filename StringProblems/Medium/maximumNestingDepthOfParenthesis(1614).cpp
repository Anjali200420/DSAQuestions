class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;

        for(int ind = 0; ind < s.length(); ind++){
            if(isdigit(s[ind])) continue;

            if(s[ind] == '(') count++;
            else if(s[ind] == ')') count --;

            ans = max(ans, count);
        }

        return ans;
    }
};