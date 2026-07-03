class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            if(arr[nums[i]] == 0){
                arr[nums[i]] = 1;
            }else{
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};