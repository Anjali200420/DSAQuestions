class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;

        int l = 0, r = 0, maxFreq = 0;
        vector<int> hash(26, 0);

        while(r < s.size()){
            hash[s[r]-'A'] += 1;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            if(((r-l+1) - maxFreq) > k){
                if(maxFreq == hash[s[l]-'A']) maxFreq--;
                hash[s[l]-'A'] -= 1;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};