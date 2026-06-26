class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(n);
        for(int i=0; i<=m-1; i++){
            for(int j=0; j<=n-1; j++){
                res[j].push_back(matrix[i][j]);
            }
        }
        return res;
    }
};