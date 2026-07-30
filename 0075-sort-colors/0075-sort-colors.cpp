class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 3 pointer approach
        // int n = nums.size();
        // int lo = 0;
        // int hi = n-1;
        int r=0, w=0, b=0;
        for(int i:nums){
            if(i==0)r++;
            else if(i==1)w++;
            else b++;
        }
        int idx=0;
        while(r || w || b){
            while(r){
                nums[idx] = 0;
                r--;
                idx++;
            }
            while(w){
                nums[idx] = 1;
                w--;
                idx++;
            }
            while(b){
                nums[idx] = 2;
                b--;
                idx++;
            }
        }

    }
};