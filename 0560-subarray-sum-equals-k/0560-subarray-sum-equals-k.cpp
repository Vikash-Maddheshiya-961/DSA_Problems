class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> prefix_map;
        prefix_map[0] = 1;

        int count = 0;
        int prefix_sum = 0;

        for(int i=0;i<n;i++){
            prefix_sum += nums[i];

            int remaining = prefix_sum - k;

            if(prefix_map.find(remaining) != prefix_map.end()){
                count += prefix_map[remaining];
            }

            prefix_map[prefix_sum]++;
        }

        return count;
    }
};