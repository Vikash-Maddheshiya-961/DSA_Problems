class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int x = 0;
        for(auto v : grid){
            for(auto val : v){
                x = x ^ val;
            }
        }

        for(int val = 1; val <= n*n; val++){
            x = x ^ val;
        }

        int a = (x & (x-1)) ^ x;

        int b0 = 0;
        int b1 = 0;

        
        for(auto v : grid){
            for(int i=0;i<n;i++){
                int val = v[i];
                if(val & a) b1 = b1 ^ val;
                else b0 = b0 ^ val;
            }
        }

        for(int val = 1;val <= n*n; val++){
            if(val & a) b1 = b1 ^ val;
            else b0 = b0 ^ val;
        }

        for(auto v:grid){
            for(auto val : v){
                if(val == b0){
                    return {b0,b1};
                }
            }
        }

        return {b1,b0};
    }
};