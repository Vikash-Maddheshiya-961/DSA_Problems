class Solution {
public:
    string helper2(vector<vector<int>> res){
        string s = "";
        for(auto v:res){
            for(int i = v.size()-1;i>=0;i--){
                s += (char)(v[i] + 48);
            }
        }
        return s;
    }
    vector<vector<int>> helper1(string s){
        int len = s.length();
        vector<vector<int>> res;
        vector<int> ans;
        ans.push_back(s[0]-'0');
        int count = 1;
        int curr;
        int prev = s[0]-'0';
        for(int i=1;i<=len;i++){
            if(i != len) curr = s[i] - '0';
            if(i!=len && prev!=curr){
                ans.push_back(count);
                res.push_back(ans);
                count = 0;
                while(ans.size()!=0){
                    ans.pop_back();
                }
                ans.push_back(curr);
                count++;
                prev = curr;
            }else if(i!=len && prev == curr){
                count++;
            }else{
                ans.push_back(count);
                res.push_back(ans);
            }
        }
        return res;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        return helper2(helper1(countAndSay(n-1)));
    }
};