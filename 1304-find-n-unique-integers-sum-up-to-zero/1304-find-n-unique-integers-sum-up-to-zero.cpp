class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        if(n==1){
            ans[0] = 0;
            return ans;
        }
        if(n%2 == 0){
            int val = 1;
            for(int i=0;i<n/2;i++){
                ans[i] = val;
                val++;
            }
            val = -1;
            for(int i=n/2;i<n;i++){
                ans[i] = val;
                val--;
            }
        }
        else{
            int val = 1;
            ans[n/2] = 0;
            for(int i=0;i<n/2;i++){
                ans[i] = val;
                val++;
            }
            val = -1;
            for(int i=n/2+1;i<n;i++){
                ans[i] = val;
                val--;
            }
        }
        return ans;
    }
};