class Solution {
public:
    int countCommas(int n) {
        int totalCommas = 0;
        
        for(int i = 1000; i <= n; i++){
            int digit = i;

            int noOfDigits = 0;
            while(digit){
                noOfDigits++;

                digit /= 10;
                if(noOfDigits > 3){
                    totalCommas++;
                    noOfDigits = 1;
                }
            }
        }

        return totalCommas;
    }
};©leetcode