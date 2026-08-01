class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre(n+1); //  Number of N before Kth hour
        pre[0] = 0;
        int count;
        for(int i=1;i<=n;i++){
            count = 0;
            if(customers[i-1] == 'N'){
                count++;
            }
            pre[i] = pre[i-1] + count;
        }
        vector<int> suf(n+1); //  Number of Y after and including Kth hour
        suf[n] = 0;
        for(int i=n-1;i>=0;i--){
            count = 0;
            if(customers[i] == 'Y'){
                count++;
            }
            suf[i] = suf[i+1] + count;
        }
        // finding penaltyi for each hour
        int min_penalty = INT_MAX;
        for(int i=0;i<=n;i++){
            pre[i] = pre[i] + suf[i];
            if(min_penalty > pre[i]) min_penalty = pre[i];
        }
        // now finding the earliest shop closing time
        for(int i=0;i<=n;i++){
            if(pre[i] == min_penalty){
                return i;
            }
        }
        return -1;
    }
};