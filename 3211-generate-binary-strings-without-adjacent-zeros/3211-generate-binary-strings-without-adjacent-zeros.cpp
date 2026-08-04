class Solution {
public:
    vector<string> res;
    void solve(string ans,int n){
        if(ans.length() == n){
            res.push_back(ans);
            return;
        }
        if(ans[ans.length()-1] != '0') solve(ans + '0',n);
        solve(ans + '1',n);
        return;
    }
    vector<string> validStrings(int n) {
        solve("0",n);
        solve("1",n);
        return res;
    }
};