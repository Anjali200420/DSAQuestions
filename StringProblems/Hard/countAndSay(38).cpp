class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for(int i = 2; i <= n; i++){
            string temp = "";
            int count = 1;

            for(int ind = 0; ind < ans.size() - 1; ind++){
                if(ans[ind] == ans[ind+1]){
                    count++;
                }
                else{
                    temp += to_string(count) + ans[ind];
                    count = 1;
                }
            }

            temp += to_string(count) + ans[ans.size()-1];
            ans = temp;
        }

        return ans;
    }
};