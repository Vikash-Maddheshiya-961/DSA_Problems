class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int ans = 0;
        int sum = 0;
        for(int i=0;i<k;i++) sum += arr[i];
        int avg = sum / k;
        if(avg >= threshold) ans++;
        int i=1;
        int j=k;
        while(j<n){
            sum = sum + arr[j] - arr[i-1];
            avg = sum / k;
            if(avg >= threshold) ans++;
            i++;
            j++;
        }
        return ans;
    }
};