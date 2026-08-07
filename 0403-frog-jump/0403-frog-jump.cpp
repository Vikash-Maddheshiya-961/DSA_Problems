class Solution {
public:
    unordered_map<int,int> mp;
    int res[2001][2001];
    bool solve(vector<int>& stones,int currstone,int prevjump){
        int n = stones.size();
        if(currstone == n-1){
            return true;
        }
        if(res[currstone][prevjump] != -1) return res[currstone][prevjump];
        int result = false;
        for(int nextjump = prevjump-1; nextjump <= prevjump+1; nextjump++){
            if(nextjump <= 0) continue;
            int nextstone = stones[currstone] + nextjump;
            if(mp.find(nextstone) != mp.end()){
                result = result || solve(stones,mp[nextstone],nextjump);
            }
        }
        return res[currstone][prevjump] = result;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]] = i;
        }
        memset(res, -1, sizeof(res));
        return solve(stones,0,0);
    }
};