class Solution {
private:
    bool fun(int ind, vector<int>& arr){
        if(ind < 0 || ind >= arr.size() || arr[ind] < 0) return false;

        if(arr[ind] == 0) return true;

        int jumpLength = arr[ind];
        arr[ind] = -arr[ind];

        if(fun(ind - jumpLength, arr)) return true;
        if(fun(ind + jumpLength, arr)) return true;

        return false;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        return fun(start, arr);
    }
};