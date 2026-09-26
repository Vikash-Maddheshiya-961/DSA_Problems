class Solution {
public:
    int m,n;
    int res[71][71][71];
    int solve(vector<vector<int>>& grid,int i,int j,int k){
        if(i >= m){
            return 0;
        }

        if(res[i][j][k] != -1) return res[i][j][k];
        int cherry;
        if(j == k){
            cherry = grid[i][j];
        }
        else{
            cherry = grid[i][j] + grid[i][k];
        }

        int maxi = INT_MIN;
        for(int c1=-1;c1<=1;c1++){
            for(int c2=-1;c2<=1;c2++){
                int newj = j + c1;
                int newk = k + c2;

                if(newj >=0 && newj < n && newk >=0 && newk < n){
                    maxi = max(maxi,solve(grid,i+1,newj,newk));
                }
            }
        }

        return res[i][j][k] = cherry + maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(res,-1,sizeof(res));
        return solve(grid,0,0,n-1);
    }
};