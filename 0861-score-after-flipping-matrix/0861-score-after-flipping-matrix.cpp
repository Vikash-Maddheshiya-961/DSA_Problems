class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // checking the first column contain the zeros --> then flip the whole row of that column
        for(int i=0;i<m;i++){
            if(grid[i][0] == 0){
                for(int j=0;j<n;j++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        // flip the column if it contain greater number of zeroes than ones
        for(int j=0 ;j<n;j++){
            int no0 = 0, no1 = 0;
            for(int i=0;i<m;i++){
                if(grid[i][j] == 0) no0++;
                else no1++;
            }
            if(no0 > no1){
                for(int i=0;i<m;i++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        // no convert each row to decimal value
        int score = 0;
        for(int i=0;i<m;i++){
            int bin = 0;
            int x = 1;
            for(int j=n-1;j>=0;j--){
                bin += grid[i][j]*x;
                x *= 2;
            }
            score += bin;
        }
        return score;
    }
};