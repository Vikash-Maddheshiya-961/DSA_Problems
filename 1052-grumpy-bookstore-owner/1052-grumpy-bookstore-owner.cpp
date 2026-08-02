class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sc = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 0) sc += customers[i];
        }
        int prev_sc = sc;
        for(int i=0;i<minutes;i++){
            if(grumpy[i] == 1) prev_sc += customers[i];
        }
        int max_sc = prev_sc;
        int i=1;
        int j=minutes;
        while(j<n){
            int curr_sc = prev_sc;
            if(grumpy[i-1] == 1) curr_sc -= customers[i-1];
            if(grumpy[j] == 1) curr_sc += customers[j];
            max_sc = max(max_sc,curr_sc);
            prev_sc = curr_sc;
            i++;
            j++;
        }
        return max_sc;
    }
};