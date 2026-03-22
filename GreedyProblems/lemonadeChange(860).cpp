class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int customers = bills.size();

        int cnt_5 = 0, cnt_10 = 0;
        for(int i = 0; i < customers; i++){
            if(bills[i] == 5) cnt_5++;
            if(bills[i] == 10){
                if(cnt_5 > 0){
                    cnt_5--;cnt_10++;
                }
                else return false;
            }
            if(bills[i] == 20){
                if(cnt_5 > 0 && cnt_10 > 0){
                    cnt_5--; cnt_10--;
                }
                else if(cnt_5 >= 3){
                    cnt_5 -= 3;
                }
                else return false;
            }
        }

        return true;
    }
};