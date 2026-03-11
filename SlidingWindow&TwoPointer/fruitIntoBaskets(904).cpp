class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;

        int l = 0, r = 0;
        map<int, int> cntOfFruit;
        while(r < fruits.size()){
            cntOfFruit[fruits[r]] += 1;

            if(cntOfFruit.size() > 2){
                cntOfFruit[fruits[l]]--;
                if(cntOfFruit[fruits[l]] == 0) cntOfFruit.erase(fruits[l]);
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};