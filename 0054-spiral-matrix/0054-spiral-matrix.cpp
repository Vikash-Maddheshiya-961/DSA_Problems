class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int val = 1;
        int total = m*n;
        int sr = 0,er = m-1;
        int sc = 0,ec = n-1;
        while(sr <= er && sc <= ec){
            for(int j=sc;j<=ec && val <= total;j++){
                ans.push_back(matrix[sr][j]);
                val++;
            }
            sr++;
            for(int i=sr;i<=er && val <= total;i++){
                ans.push_back(matrix[i][ec]);
                val++;
            }
            ec--;
            for(int j=ec;j>=sc && val <= total;j--){
                ans.push_back(matrix[er][j]);
                val++;
            }
            er--;
            for(int i=er;i>=sr && val <= total;i--){
                ans.push_back(matrix[i][sc]);
                val++;
            }
            sc++;
        }
        return ans;
    }
};