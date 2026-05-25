class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mpp;

        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int ind = 0;
        int ans = 0;
        while(ind < s.length()){
            if(mpp[s[ind]] >= mpp[s[ind+1]]){
                ans += mpp[s[ind]];
            }
            else{
                ans += (mpp[s[ind+1]] - mpp[s[ind]]);
                ind++;
            }

            ind++;
        }

        return ans;
    }
};