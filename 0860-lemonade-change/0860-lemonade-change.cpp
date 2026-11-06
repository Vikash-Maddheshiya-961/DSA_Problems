class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int,int> mp;

        for(int pay : bills){
            mp[pay]++;
            if(pay == 10){
                if(mp[5] >= 1){
                    mp[5]--;
                }
                else{
                    return false;
                }
            }
            else if(pay == 20){
                if(mp[10] >= 1 && mp[5] >= 1){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5] >= 3){
                    mp[5] -= 3;
                }
                else return false;
            }
        }

        return true;
    }
};