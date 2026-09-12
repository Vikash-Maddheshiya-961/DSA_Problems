class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int extra = -1;
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
            int sum = digits[i] + carry;
            if(sum == 10){
                digits[i] = 0;
                carry = 1;
                continue;
            }
            digits[i] = sum;
            carry = -1;
            break;
        }
        if(carry == -1) return digits;
        
        digits.push_back(-1);
        for(int i=digits.size()-1;i>=1;i--){
            digits[i] = digits[i-1];
        }

        digits[0] = 1;

        return digits;
    }
};