class Solution {
public:
    unordered_map<int,int> mp;
    int res[2001][2001];
    bool solve(vector<int>& stones,int curr_stone_idx,int prevjmp){
        int n = stones.size();
        if(curr_stone_idx == n-1){
            return true;
        }
        if(res[curr_stone_idx][prevjmp] != -1) return res[curr_stone_idx][prevjmp];
        bool result = false;
        for(int nextjmp = prevjmp-1; nextjmp <= prevjmp+1; nextjmp++){
            if(nextjmp <= 0) continue;
            int next_stone = stones[curr_stone_idx] + nextjmp;
            if(mp.find(next_stone) != mp.end()){
                result = result || solve(stones,mp[next_stone],nextjmp);
            }
        }
        return res[curr_stone_idx][prevjmp] = result;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        int n = stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]] = i;
        }
        memset(res , -1, sizeof(res));
        return solve(stones,0,0);
    }
};