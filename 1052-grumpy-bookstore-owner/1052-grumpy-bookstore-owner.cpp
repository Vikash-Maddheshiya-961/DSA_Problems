class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int k = minutes;
        int LOS = 0;
        for(int i=0;i<k;i++){
            if(grumpy[i] == 1){
                LOS += customers[i];
            }
        }

        int left = 1;
        int right = k;
        int MAX_LOS = LOS;
        while(right < n){
            if(grumpy[left-1] == 1){
                LOS -= customers[left-1];
            }
            if(grumpy[right] == 1){
                LOS += customers[right];
            }

            MAX_LOS = max(MAX_LOS,LOS);

            left++;
            right++;
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 0){
                sum += customers[i];
            }
        }

        return sum + MAX_LOS;
    }
};