class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int val = 1;
        int i=0;
        while(k!=0 && i<n){
            if(arr[i]!=val){
                val++;
                k--;
            }
            else{
                val++;
                i++;
            }
        }
        if(k==0) return val - 1;
        while(k != 1){
            val++;
            k--;
        }
        return val;
    }
};