class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=n-1; j>=0; j--){
                if(target > matrix[i][j]) break;
                else{
                    if(matrix[i][j] == target){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};