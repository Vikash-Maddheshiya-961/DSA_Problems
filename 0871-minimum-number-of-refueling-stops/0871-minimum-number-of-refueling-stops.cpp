class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<int> v;
        v.push_back(target);
        v.push_back(0);
        stations.push_back(v);

        int n = stations.size();
        priority_queue<int> pq;

        int fuel = startFuel;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(stations[i][0] > fuel){
                while(!pq.empty() && stations[i][0] > fuel){
                    int gas = pq.top();
                    pq.pop();
                    fuel += gas;
                    ans++;
                }
                if(stations[i][0] > fuel) return -1;
            }
            pq.push(stations[i][1]);
        }
        return ans;
    }
};