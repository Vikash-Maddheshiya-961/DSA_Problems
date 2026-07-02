class Solution {
public:
    int minimumSum(int num) {
        vector<int> digit;
        while(num!=0){
            digit.push_back(num%10);
            num /= 10;
        }
        sort(digit.begin(),digit.end());
        int num1 = digit[0]*10+digit[2];
        int num2 = digit[1]*10+digit[3];
        return num1+num2;
    }
};