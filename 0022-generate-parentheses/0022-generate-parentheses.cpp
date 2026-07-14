class Solution {
public:
    void solve(vector<string>& res,string s,int op,int cl,int n){
        if(op == n && cl == n){
            res.push_back(s);
            return;
        }
        if(op<n){
            solve(res,s+"(",op+1,cl,n);
        }
        if(cl < op){
            solve(res,s+")",op,cl+1,n);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res,"",0,0,n);
        return res;
    }
};