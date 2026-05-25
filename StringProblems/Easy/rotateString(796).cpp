class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string str = s;

        for(int ind1 = 0; ind1 < s.length(); ind1++){
            rotate(str.begin(), str.begin() + 1, str.end());
            if(str == goal) return true;
        }

        return false;
    }
};