class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int r = 0, l = 0;

        vector<int> hash(256, -1);
        while(r < s.size()){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }

            ans = max(ans, r-l+1);
            hash[s[r]] = r;
            r++;
        }

        return ans;
    }
};