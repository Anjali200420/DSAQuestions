class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        for(int ind = n-1; ind >= 0; ind--){
            int ch = num[ind];

            if(ch%2 != 0){
                return num.substr(0, ind+1);
            }
        }

        return "";
    }
};