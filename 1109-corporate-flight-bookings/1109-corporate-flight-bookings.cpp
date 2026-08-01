class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int r = bookings.size();
        int c = bookings[0].size();
        vector<int> ans(n,0);
        for(int i=0;i<r;i++){
            int s = bookings[i][0]-1;
            int e = bookings[i][1]-1;
            int seat = bookings[i][2];
            while(s<=e){
                ans[s] += seat;
                s++;
            }
        }
        return ans;
    }
};