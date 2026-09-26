class Solution {
public:
    vector<vector<int>> res;
    int n;
    int solve(vector<vector<int>>& matrix,int i,int j){
        if(j < 0 || j >= n) return INT_MAX;

        if(i == n-1) return matrix[i][j];

        if(res[i][j] != INT_MIN) return res[i][j];

        return res[i][j] = matrix[i][j] + min({solve(matrix,i+1,j-1),solve(matrix,i+1,j),solve(matrix,i+1,j+1)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        res.assign(n+1,vector<int>(n+1,INT_MIN));
        int result = INT_MAX;
        for(int j=0;j<n;j++){
            result = min(result,solve(matrix,0,j));
        }

        return result;
    }
};