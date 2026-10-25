class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int x = 0;
        for(unsigned int val:nums){
            x ^= val;
        }

        unsigned int n = (x & (x - 1)) ^ x;
        unsigned int setbit;
        for(unsigned int i=0;i<=31;i++){
            if(n & (1 << i)){
                setbit = i;
                break;
            }
        }

        unsigned int b1 = 0;
        unsigned int b2 = 0;

        for(unsigned int val:nums){
            if(val & (1 << setbit)) b1 ^= val;
            else b2 ^= val;
        }

        return {static_cast<int>(b1),static_cast<int>(b2)};
    }
};