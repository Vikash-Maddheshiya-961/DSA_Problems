class Solution {
public:
    int GCD(int a,int b){
        if(b == 0) return a;
        return GCD(b,a%b);
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