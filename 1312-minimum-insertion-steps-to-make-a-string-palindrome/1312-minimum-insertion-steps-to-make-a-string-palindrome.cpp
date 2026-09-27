class Solution {
public:
    int res[501][501];
    int solve(string &s,int i,int j){
        if(i >= j) return 0;

        if(res[i][j] != -1) return res[i][j];
        if(s[i] == s[j]) return res[i][j] = solve(s,i+1,j-1);

        return res[i][j] = 1 + min(solve(s,i+1,j),solve(s,i,j-1));
    }
    int minInsertions(string s) {
        int n = s.length();
        memset(res,-1,sizeof(res));
        return solve(s,0,n-1);
    }
};