// User function Template for C++
#include <iostream>
#include <bit/stdc++.h>

using namespace std;

class Solution {
  private:
    bool fun(long long ind, long long N){
        if(ind < 0) return false;
    
        if(ind == 0) return true;
        
        return fun(ind - (N-ind), N);
    }
    
  public:
    // string canJump(long long N) {
    //     // code here
    //     if(fun(N-1, N)) return "True";
        
    //     return "False";
    // }

    string canJump(long long N) {
        // code here
        long long ind = 1;
        
        while(ind <= N){
            if(ind == N) return "True";
            if(ind > N) return "False";
            
            ind += ind;
        }
        
        return "False";
    }
};