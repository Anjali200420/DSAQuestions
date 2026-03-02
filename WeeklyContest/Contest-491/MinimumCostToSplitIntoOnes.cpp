class Solution {
private:
    int fun(int n){
        if(n <= 1) return 0;

        if(n % 2 != 0) return n-1 + fun(n-1);
        
        return (n/2)*(n/2) + fun(n/2) + fun(n/2);
    }
public:
    int minCost(int n) {
        return fun(n);
    }
};