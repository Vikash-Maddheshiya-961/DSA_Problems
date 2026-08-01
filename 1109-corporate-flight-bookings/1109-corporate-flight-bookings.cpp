class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int r = bookings.size();
        int c = bookings[0].size();
        vector<int> ans(n);
        for(int i=0;i<r;i++){
            int f = bookings[i][0] - 1;
            int l = bookings[i][1] - 1;
            int p = bookings[i][2];
            ans[f] += p;
            if(l == n-1) continue;
            ans[l+1] -= p; 
        }
        for(int i=1;i<n;i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};