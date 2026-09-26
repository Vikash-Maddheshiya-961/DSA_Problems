class Solution {
public:
    int n;
    int res[101];
    int solve(string s,int idx){
        if(idx == n) return 1;

        if(res[idx] != -1) return res[idx];
        if(s[idx] == '0') return 0;
        int way1 = solve(s,idx+1);
        int way2 = 0;
        if(idx+1 < n && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))) way2 = solve(s,idx+2);

        return res[idx] = way1 + way2;
    }
    int numDecodings(string s) {
        n = s.length();
        memset(res,-1,sizeof(res));
        return solve(s,0);
    }
};