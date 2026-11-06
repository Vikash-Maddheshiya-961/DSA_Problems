class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for(int pay : bills){
            if(pay == 5){
                five++;
            }
            else if(pay == 10){
                ten++;
                if(five >= 1){
                    five--;
                }
                else{
                    return false;
                }
            }
            else if(pay == 20){
                twenty++;
                if(ten >= 1 && five >= 1){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else return false;
            }
        }

        return true;
    }
};