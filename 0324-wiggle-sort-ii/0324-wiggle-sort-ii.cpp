class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto middle = nums.begin() + n/2;
        nth_element(nums.begin(),middle,nums.end());
        int median = *middle;


        auto virtualidx = [&](int &mid){
            return (1 + 2 * mid) % (n | 1);
        };

        // dutch flag algo
        int lo = 0;
        int mid = 0;
        int hi = n-1;

        while(mid <= hi){
            int vlo = virtualidx(lo);
            int vmid = virtualidx(mid);
            int vhi = virtualidx(hi);

            if(nums[vmid] > median){
                swap(nums[vmid],nums[vlo]);
                lo++;
                mid++;
            }
            else if(nums[vmid] < median){
                swap(nums[vmid],nums[vhi]);
                hi--;
            }
            else mid++;
        }
        
        return;
    }
};