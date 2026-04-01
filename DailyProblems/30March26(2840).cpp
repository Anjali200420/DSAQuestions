class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char, int> mpp1;
        map<char, int> mpp2;

        for(int i = 0; i < s1.length(); i++){
            mpp1[s1[i]] += 1;
            mpp2[s2[i]] += 1;
        }

        for(int i = 0; i < 26; i++){
            char ch = i + 'a';
            if(mpp1[ch] != mpp2[ch]) return false;
        }

        for(int i = 0; i < s1.length(); i++){
            char ch1 = s1[i];
            char ch2 = s2[i];

            if(ch1 == ch2) continue;

            for(int j = i+2; j < s1.length(); j += 2){
                if(s1[j] == ch2){
                    swap(s1[i], s1[j]);
                    break;
                }
            }

            if(s1 == s2) return true;
        }

        return s1 == s2;
    }
};