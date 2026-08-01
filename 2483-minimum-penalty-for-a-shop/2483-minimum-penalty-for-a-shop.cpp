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
        // finding penaltyi for each hour
        int min_penalty = INT_MAX;
        for(int i=0;i<=n;i++){
            N_before[i] = N_before[i] + Y_after[i];
            if(min_penalty > N_before[i]) min_penalty = N_before[i];
        }
        // now finding the earliest shop closing time
        for(int i=0;i<=n;i++){
            if(N_before[i] == min_penalty){
                return i;
            }
        }
        return -1;
    }
};