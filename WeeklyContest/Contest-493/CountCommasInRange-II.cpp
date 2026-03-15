class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;

        int cntDigit = 0;
        long long digit = n;
        while(digit){
            cntDigit++;

            digit /= 10;
        }

        if(cntDigit >= 4 && cntDigit <= 6){
            totalCommas = n - 1000LL + 1;
        }
        else if(cntDigit >= 7 && cntDigit <= 9){
            totalCommas = 999LL*1000LL + 2*(n - 1000000LL + 1);
        }
        else if(cntDigit >= 10 && cntDigit <= 12){
            totalCommas = 999LL*1000LL + 2*999LL*1000000LL + 3*(n - 1000000000LL + 1);
        }
        else if(cntDigit >= 13 && cntDigit <= 15){
            totalCommas = 999LL*1000LL + 2*999LL*1000000LL + 3*999LL*1000000000LL + 4*(n - 1000000000000LL + 1);
        }
        else if(cntDigit == 16){
            totalCommas = 999LL*1000LL + 2*999LL*1000000LL + 3*999LL*1000000000LL + 4*999LL*1000000000000LL + 5*(n - 1000000000000000LL + 1);
        }

        return totalCommas;
    }
};©leetcode