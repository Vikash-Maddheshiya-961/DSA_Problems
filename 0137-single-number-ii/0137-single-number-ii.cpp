class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int bitIndex = 0; bitIndex <= 31; bitIndex++){
            int cnt = 0;

            for(int val:nums){
                if(val & (1 << bitIndex)){
                    cnt++;
                }
            }

            if(cnt % 3 == 1) ans = ans | (1 << bitIndex);
        }

        return ans;
    }
};