class Solution {
private:
    int reverse(int n){
        int revNum = 0;

        while(n){
            int digit = n%10;
            revNum = revNum*10 + digit;

            n /= 10;
        }

        return revNum;
    }

public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};