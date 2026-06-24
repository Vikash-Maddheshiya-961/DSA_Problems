class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 3 pointer approach 
        // low = 0, mid = 0 ,high = n-1
        // 0 to low-1 --> 0 , high+1 to n-1 --> 2
        // low to mid-1 --> 1 (automatically happen after satisfying the above two conditon)
        int n = nums.size();
        int l=0, m=0,h=n-1;
        while(m<=h){
            if(nums[m] == 2){
                swap(nums[h],nums[m]);
                h--;
            }
            else if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else{
                m++;
            }

        }
    }
};