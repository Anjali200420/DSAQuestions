class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int res = 0, pos = 0;
        while((1LL << pos) <= n){
            if(((1LL << pos) & n) == 0) res |= (1LL << pos);
            pos++;
        }

        return res;
    }
};