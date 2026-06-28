class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        for(int i=0; i<numRows; i++){
            pascal[i].push_back(1);
            int j=1;
            while(j<=i){
                int r = j-1;
                pascal[i].push_back(((i-r)*pascal[i][r])/(r+1));
                j++;
            }
        }
        return pascal;
    }
};