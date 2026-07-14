class Solution {
public:
    int GCD(int a,int b){
        int q = a/b;
        int r = a - q*b;
        if(r == 0) return b;
        return GCD(b,r);
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(max < nums[i]) max = nums[i];
            if(min > nums[i]) min = nums[i];
        }
        return GCD(max,min);
    }
};