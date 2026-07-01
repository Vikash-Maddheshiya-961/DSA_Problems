class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans;
        string temp;
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            ans = ans + temp + " ";
        }
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};