class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int ind = 0;

        
        // 1. Removing Whitespace
        while(ind < n && !(s[ind] == '-' || s[ind] == '+' || isdigit(s[ind])) && s[ind] == ' '){
            ind++;
        }
            

        // 2. Signedness
        int sign = 1;
        if(ind < n && (s[ind] == '-' || s[ind] == '+')){
            if(s[ind] == '-') sign = -1;
            ind++;
        }

        // 3. Conversion
        while(ind < n && s[ind] == '0')
            ind++;

        long long total = 0;
        while(ind < n && isdigit(s[ind])){
            int digit = s[ind] - '0';

            total = total * 10 + digit;

            // 4. Rounding
            if(sign == 1 && total > INT_MAX) return INT_MAX;
            if(sign == -1 && -total < INT_MIN) return INT_MIN;

            ind++;
        }

        
       return sign*total;
    }
};