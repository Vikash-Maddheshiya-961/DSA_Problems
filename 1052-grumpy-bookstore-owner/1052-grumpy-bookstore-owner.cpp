class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 0){
                sum += customers[i];
            }
        }

        int k = minutes;
        for(int i=0;i<k;i++){
            if(grumpy[i] == 1){
                sum += customers[i];
            }
        }

        int left = 1;
        int right = k;
        int max_sum = sum;
        while(right < n){
            if(grumpy[left-1] == 1){
                sum -= customers[left-1];
            }
            if(grumpy[right] == 1){
                sum += customers[right];
            }

            max_sum = max(max_sum,sum);

            left++;
            right++;
        }

        return max_sum;
    }
};