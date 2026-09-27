class Solution {
public:
    int res[1001][1001];
    int solve(string& s,string& t,int i,int j){
        if(j<0) return 1;
        if(i<0 && j>=0) return 0;
        if(res[i][j] != -1) return res[i][j];
        if(s[i] == t[j]) return res[i][j] = solve(s,t,i-1,j-1) + solve(s,t,i-1,j);

        return res[i][j] = solve(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        memset(res,-1,sizeof(res));
        return solve(s,t,m-1,n-1);
    }
};