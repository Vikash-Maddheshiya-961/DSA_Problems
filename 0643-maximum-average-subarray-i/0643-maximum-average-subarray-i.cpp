class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        double avg = sum / k;
        double max_avg = avg;
        int i=1;
        int j=k;
        while(j<n){
            sum += nums[j] - nums[i-1];
            avg = sum / k;
            max_avg = max(max_avg,avg);
            i++;
            j++;
        }
        return max_avg;
    }
};