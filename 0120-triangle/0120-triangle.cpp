class Solution {
public:
    int n;
    vector<vector<int>> res;
    int solve(vector<vector<int>>& triangle, int i,int j){
        if(i == n-1) return triangle[i][j];
        if(res[i][j] != INT_MIN) return res[i][j];
        return res[i][j] = triangle[i][j] + min(solve(triangle,i+1,j),solve(triangle,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        res.assign(201,vector<int>(201,INT_MIN));
        return solve(triangle,0,0);
    }
};