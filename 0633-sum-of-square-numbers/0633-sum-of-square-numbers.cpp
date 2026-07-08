class Solution {
public:
    bool judgeSquareSum(int c) {
        long long k = (long long)c;
        long long left = 0;
        long long right = sqrt(k);
        while(left <= right){
            long long sum = left*left + right*right;
            if(sum == k) return true;
            else if(sum < k) left++;
            else right--;
        }
        return false;
    }
};