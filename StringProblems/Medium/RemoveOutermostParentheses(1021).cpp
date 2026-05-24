class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";

        int count = 0;
        for(int ind = 0; ind < s.length(); ind++){
            char ch = s[ind];
            if(count > 1) ans += ch;
            else if(count == 1 && ch != ')') ans += ch;

            if(ch == '(') count += 1;
            else if(ch == ')') count -= 1;
        }

        return ans;
    }
};