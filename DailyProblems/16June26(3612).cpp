class Solution {
public:
    string processStr(string s) {
        int n = s.length();

        string res = "";
        for(int ind = 0; ind < n; ind++){
            if(isalpha(s[ind])) res.push_back(s[ind]);
            else if(s[ind] == '*'){
                if(res.length() > 0) res.pop_back();
            } 
            else if(s[ind] == '#') res += res;
            else if(s[ind] == '%') reverse(res.begin(), res.end());

            cout << res << endl;
        }

        return res;
    }
};