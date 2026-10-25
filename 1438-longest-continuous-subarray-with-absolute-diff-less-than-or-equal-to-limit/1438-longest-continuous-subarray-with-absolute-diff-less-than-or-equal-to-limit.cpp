class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        deque<int> maxdq;
        deque<int> mindq;

        int left = 0;
        int right = 0;

        int max_len = 0;
        while(right < n){
            while(!maxdq.empty() && maxdq.back() < nums[right]){
                maxdq.pop_back();
            }

            maxdq.push_back(nums[right]);

            while(!mindq.empty() && mindq.back() > nums[right]){
                mindq.pop_back();
            }

            mindq.push_back(nums[right]);

            while(maxdq.front() - mindq.front() > limit){
                if(maxdq.front() == nums[left]){
                    maxdq.pop_front();
                }

                if(mindq.front() == nums[left]){
                    mindq.pop_front();
                }

                left++;
            }

            int curr_len = right - left + 1;
            max_len = max(max_len,curr_len);

            right++;
        }

        return max_len;
    }
};