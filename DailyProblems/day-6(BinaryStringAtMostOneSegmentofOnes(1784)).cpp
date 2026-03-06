class Solution {
public:
    bool checkOnesSegment(string s) {
        int sz = s.size();

        bool firstZero = false;
        for(int i = 0; i < sz; i++){
            if(s[i] == '0' && !firstZero) 
                firstZero = true;

            if(s[i] == '1' && firstZero) return false;
        }

        return true;
    }
};