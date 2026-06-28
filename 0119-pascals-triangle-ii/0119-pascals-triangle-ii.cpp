class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long int n = rowIndex;
        vector<int> res(n+1);
        res[0] = 1;
        for(int j=1; j<=n; j++){
            long long int r = j-1;
            res[j] = ((n-r)*res[r])/(r+1);
        }
        return res;
    }
};