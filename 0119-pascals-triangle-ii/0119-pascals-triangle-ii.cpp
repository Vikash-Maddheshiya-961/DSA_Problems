class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long int n = rowIndex;
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<=n;i++){
            long long int r = i-1;
            ans.push_back(((n-r)*ans[r])/(r+1));
        }
        return ans;
    }
};