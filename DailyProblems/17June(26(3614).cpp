class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        vector<long long> lens;
        long long len = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                len = max(len-1, 0LL);
            }
            else if(s[i] == '#'){
                len *= 2;
            }
            else if(s[i] != '%'){
                len++;
            }
        }

        if(k >= len) return '.';

        for(int i = n-1;; i--){
            char ch = s[i];

            switch (ch){
                case '*':
                    len++;
                    break;
                case '#':
                    if(k >= len/2){
                        k -= (len/2);
                    }
                    len /= 2;
                    break;
                case '%':
                    k = len - 1 - k;
                    break;
                default:
                    if(len == k+1) return s[i];
                    len--;
            }
        }

        return '.';
    }
};