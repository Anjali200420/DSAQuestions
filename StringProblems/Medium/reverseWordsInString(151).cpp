class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        int n = s.length();
        int len = 0;

        for(int ind = n-1; ind >= 0; ind--){
            char ch = s[ind];
            if(ch == ' ' && len == 0) continue;
            else if(ch == ' '){
                ans += s.substr(ind+1, len) + " ";
                len = 0;
            }
            else{
                len++;
            }
        }

        if(len > 0){
            ans += s.substr(0, len);
        }
        else{
            ans = ans.substr(0, ans.length()-1);
        }

        return ans;
    }
};