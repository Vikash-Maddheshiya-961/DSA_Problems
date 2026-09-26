class Solution {
public:
    int res[101][101];
    int solve(int i,int j,int &m,int &n){
        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(res[i][j] != -1) return res[i][j];
        return res[i][j] = solve(i,j+1,m,n) + solve(i+1,j,m,n);
    }
    int uniquePaths(int m, int n) {
        memset(res,-1,sizeof(res));
        return solve(0,0,m,n);
    }
};