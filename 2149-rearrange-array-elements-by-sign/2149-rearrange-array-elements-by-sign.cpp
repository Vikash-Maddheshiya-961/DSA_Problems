class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        for(int val:nums){
            if(val < 0){
                neg.push_back(val);
            }
            else {
                pos.push_back(val);
            }
        }

        int j=0;
        int k=0;
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                nums[i] = pos[j];
                j++;
            }
            else{
                nums[i] = neg[k];
                k++;
            }
        }

        return nums;
    }
};