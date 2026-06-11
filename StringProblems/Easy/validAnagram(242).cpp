class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> vis(26, 0);

        for(int ind = 0; ind < s.length(); ind++){
            vis[s[ind] - 'a'] += 1;
            vis[t[ind] - 'a'] -= 1;
        }

        for(int ind = 0; ind < s.length(); ind++){
            if(vis[s[ind] - 'a'] != 0) return false;
        }

        return true;
    }
};