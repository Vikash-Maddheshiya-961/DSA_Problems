class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        for(int i=1;i<n;i++){
            arr[i] += arr[i-1];
        }
        int ans = 0;
        int avg = arr[k-1] / k;
        if(avg >= threshold) ans++;
        int i=1;
        int j=k;
        while(j<n){
            int sum = arr[j] - arr[i-1];
            avg = sum / k;
            if(avg >= threshold) ans++;
            i++;
            j++;
        }
        return ans;
    }
};