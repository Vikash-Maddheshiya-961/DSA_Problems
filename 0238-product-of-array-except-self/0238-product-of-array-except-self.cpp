class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // making prefix array
        vector<int> prefix(n);
        prefix[0] = 1;
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        // making suffix array
        int p = nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefix[i] *= p;
            p *= nums[i];
        }
        return prefix;
    }
};