class Solution {
public:
    vector<vector<int>> res;
    int m,n;
    int solve(vector<vector<int>>& dungeon,int i,int j){
        if(i >= m || j >= n) return INT_MAX;

        if(i == m-1 && j == n-1){
            if(dungeon[i][j] <= 0) return abs(dungeon[i][j]) + 1;
            return 1;
        }

        if(res[i][j] != INT_MIN) return res[i][j];

        int mini = min(solve(dungeon,i+1,j),solve(dungeon,i,j+1));

        int health = mini - dungeon[i][j];

        if(health <= 0) return 1;

        return res[i][j] = health;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        res.assign(m+1,vector<int>(n+1,INT_MIN));
        return solve(dungeon,0,0);
    }
};