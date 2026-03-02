class Solution {
public:
    string trimTrailingVowels(string s) {
        string vowel = "aeiou";

        int i = s.size() - 1;
        
        while(i >= 0 && vowel.find(s[i]) != string :: npos){
            i--;
        }
        return s.substr(0, i+1);
    }
};