class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> N_before(n+1);
        N_before[0] = 0;
        for(int i=1;i<=n;i++){
            if(customers[i-1] == 'N'){
                N_before[i] = N_before[i-1]+1;
            }else{
                N_before[i] = N_before[i-1];
            }
        }
        vector<int> Y_after(n+1);
        Y_after[n] = 0;
        for(int i=n-1;i>=0;i--){
            if(customers[i] == 'Y'){
                Y_after[i] = Y_after[i+1] + 1;
            }
            else{
                Y_after[i] = Y_after[i+1];
            }
        }
        vector<int> penalty(n+1);
        for(int i=0;i<=n;i++){
            penalty[i] = N_before[i] + Y_after[i];
        }
        int min_penalty = penalty[0];
        for(int i=1;i<=n;i++){
            if(min_penalty > penalty[i]) min_penalty = penalty[i];
        }
        int closing_hour;
        for(int i=0;i<=n;i++){
            if(penalty[i] == min_penalty){
                return i;
            }
        }
        return -1;
    }
};