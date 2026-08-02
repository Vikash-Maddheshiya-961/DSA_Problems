class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int prev_los = 0; //  previous loss of satisfation
        for(int i=0;i<minutes;i++){
            if(grumpy[i] == 1) prev_los += customers[i];
        }
        int idx = 0;
        int max_los = prev_los; //  maximum loss of satisfaction
        int i = 1;
        int j = minutes;
        while(j<n){
            int curr_los = prev_los;
            if(grumpy[i-1] == 1) curr_los -= customers[i-1];
            if(grumpy[j] == 1) curr_los += customers[j];
            if(curr_los > max_los){
                max_los = curr_los;
                idx = i;
            }
            prev_los = curr_los;
            i++;
            j++;
        }
        for(int i=idx;i<=idx+minutes-1;i++){
            if(grumpy[i] == 1) grumpy[i] = 0;
        }
        int max_s = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 0) max_s += customers[i];
        }
        return max_s;
    }
};