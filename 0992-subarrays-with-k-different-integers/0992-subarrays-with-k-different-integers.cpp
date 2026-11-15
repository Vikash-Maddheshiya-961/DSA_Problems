class Solution {
private:
    int solve(vector<int>& nums,int k){
        int n = nums.size();

        unordered_map<int,int> mp;

        int cnt = 0;

        int left = 0;
        int right = 0;

        while(right < n){
            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }

            cnt += (right - left + 1);
            right++;
        }

        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};