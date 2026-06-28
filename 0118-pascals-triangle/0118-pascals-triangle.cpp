class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        for(int i=0;i<numRows;i++){
            vector<int> v(i+1,1);
            pascal[i] = v;
        }
        for(int i=2 ; i<numRows; i++){
            for(int j=1; j<i ;j++){
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
        }
        return pascal;
    }
};