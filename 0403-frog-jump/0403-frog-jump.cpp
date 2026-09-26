class Solution {
public:
    int n;
    map<int,int> mp;
    int res[2001][2001];
    bool solve(vector<int>& stones,int idx,int prev_jmp){
        if(idx == n-1) return true;
        if(res[idx][prev_jmp]!=-1) return res[idx][prev_jmp];
        int result = false;
        for(int nxt_jmp = prev_jmp - 1; nxt_jmp <= prev_jmp + 1; nxt_jmp++){
            if(nxt_jmp <= 0) continue;
            int nextstone = stones[idx] + nxt_jmp;
            if(mp.find(nextstone) != mp.end()){
                result = result || solve(stones,mp[nextstone],nxt_jmp);
            }
        }
        

        return res[idx][prev_jmp] = result;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != stones[0] + 1) return false;
        n = stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]] = i;
        }
        memset(res,-1,sizeof(res));
        return solve(stones,0,0);
    }
};