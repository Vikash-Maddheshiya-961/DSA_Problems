class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int fr = 0, lr = n-1, fc = 0, lc=n-1;
        int tne = n*n;
        int num = 1;
        while(fr<=lr && fc<=lc){
            for(int i=fc; i<=lc && num<=tne; i++){
                res[fr][i] = num;
                num++;
            }
            fr++;
            for(int i=fr; i<=lr && num<=tne; i++){
                res[i][lc] = num;
                num++;
            }
            lc--;
            for(int i=lc; i>=fc && num<=tne; i--){
                res[lr][i] = num;
                num++;
            }
            lr--;
            for(int i=lr; i>=fr && num<=tne; i--){
                res[i][fc] = num;
                num++;
            }
            fc++;
        }
        return res;
    }
};