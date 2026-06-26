class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int fr = 0, lr = m-1, fc = 0, lc = n-1;
        int tne = m*n;
        int count = 0;
        while(fr<=lr && fc<=lc){
            for(int i=fc;i<=lc && count<tne;i++){
                res.push_back(matrix[fr][i]);
                count++;
            }
            fr++;
            for(int i=fr;i<=lr && count<tne;i++){
                res.push_back(matrix[i][lc]);
                count++;
            }
            lc--;
            for(int i=lc;i>=fc && count<tne;i--){
                res.push_back(matrix[lr][i]);
                count++;
            }
            lr--;
            for(int i=lr;i>=fr && count<tne;i--){
                res.push_back(matrix[i][fc]);
                count++;
            }
            fc++;
        }
        return res;
    }
};