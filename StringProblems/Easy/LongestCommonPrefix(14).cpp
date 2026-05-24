class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string str = strs[i];

            int ind = 0;
            while(ind < ans.length() && ind < str.length() && ans[ind] == str[ind]){
                ind++;
            }

            ans = ans.substr(0, ind);
        }

        return ans;
    }
};