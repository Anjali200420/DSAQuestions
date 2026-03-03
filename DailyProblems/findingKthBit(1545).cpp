class Solution {
private:
    string reverseStr(string str){
        string res = str;
        reverse(res.begin(), res.end());

        return res;
    }

    string invert(string str){
        string new_str = "";

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '0') new_str += '1';
            else new_str += '0';
        }

        string ans = reverseStr(new_str);
        return ans;
    }

    char creatingNthBinaryString(int n, int k){
        string prev_str = "0";
        string cur_str = "";
        for(int i = 1; i < n; i++){
           cur_str = prev_str + '1' + invert(prev_str);

           prev_str = cur_str;
        }

        for(int i = 0; i < prev_str.size(); i++){
            if(i == k-1) return prev_str[i];
        }

        return '-1';
    }

public:
    char findKthBit(int n, int k) {
        return creatingNthBinaryString(n, k);
    }
};