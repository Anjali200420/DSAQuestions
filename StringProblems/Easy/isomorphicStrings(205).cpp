class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mpp1;
        map<char, char> mpp2;

        for(int ind = 0; ind < s.length(); ind++){
            char ch1 = s[ind];
            char ch2 = t[ind];
            if(mpp1.find(ch1) == mpp1.end()){
                mpp1[ch1] = ch2;
            }
            else if(mpp1[ch1] != ch2){
                return false;
            }

            if(mpp2.find(ch2) == mpp2.end()){
                mpp2[ch2] = ch1;
            }
            else if(mpp2[ch2] != ch1){
                return false;
            }
        }

        return true;
    }
};