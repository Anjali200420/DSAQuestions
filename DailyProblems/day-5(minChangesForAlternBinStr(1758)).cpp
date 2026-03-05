class Solution {
public:
    int minOperations(string s) {
        int opStart0 = 0;
        int opStart1 = 0;

        for(int i = 0; i < s.size(); i++){
            char expected0 = (i%2 == 0) ? '0' : '1';
            char expected1 = (i%2 == 0) ? '1' : '0';

            if(s[i] != expected0) opStart0++;
            if(s[i] != expected1) opStart1++;
        }

        return min(opStart0, opStart1);
    }
};