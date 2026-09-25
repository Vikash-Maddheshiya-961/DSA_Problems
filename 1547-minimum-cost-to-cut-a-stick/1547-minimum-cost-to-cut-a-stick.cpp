class Solution {
public:
    int solve(vector<int>&cuts,int i,int j,map<pair<int,int>,int>& mp){
        if(i == j+1) return 0;
        if(mp.find({i,j}) != mp.end()) return mp[{i,j}];
        int mini_cost = 1e9;
        for(int k=0;k<cuts.size();k++){
            if(cuts[k] > i && cuts[k] < j){
                int curr_cost = solve(cuts,i,cuts[k],mp) + solve(cuts,cuts[k],j,mp) + (j-i);
                mini_cost = min(mini_cost,curr_cost);
            }
        }

        if(mini_cost == 1e9) return mp[{i,j}] = 0;
        return mp[{i,j}] = mini_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        map<pair<int,int>,int> mp;
        return solve(cuts,0,n,mp);
    }
};