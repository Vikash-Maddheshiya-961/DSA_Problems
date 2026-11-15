class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double curr_sum = 0;

        for(int i=0;i<k;i++){
            curr_sum = curr_sum + nums[i];
        }

        double max_avg = curr_sum / k;

        int left = 1;
        int right = k;

        while(right < n){
            curr_sum = curr_sum + nums[right] - nums[left-1];
            double curr_avg = curr_sum/k;
            max_avg = max(max_avg,curr_avg);
            left++;
            right++;
        }

        return max_avg;
    }
};