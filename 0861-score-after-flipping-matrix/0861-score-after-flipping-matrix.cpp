class Solution {
public:
    int decimal(vector<int> v){
        int n = v.size();
        int dec = 0;
        int x = 1;
        for(int i=n-1; i>=0; i--){
            dec += v[i]*x;
            x *= 2;
        }
        return dec;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 1.all 1's in 0th column by fliping the whole row;
        for(int i=0; i<m; i++){
            if(grid[i][0] == 0){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        //2. Flip the column where no0 > no1
        for(int j=0; j<n; j++){
            int no0 = 0, no1 = 0;
            for(int i=0; i<m; i++){
                if(grid[i][j] == 0) no0++;
                else no1++;
            }
            if(no0 > no1){
                for(int i=0; i<m; i++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        //3. Find score by converting each to decimal
        int score = 0;
        for(int i=0; i<m; i++){
            score += decimal(grid[i]);
        }
        return score;
    }
};