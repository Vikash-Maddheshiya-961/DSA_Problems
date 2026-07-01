class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans;
        sort(strs.begin(),strs.end());
        int len = min(strs[0].length(),strs[n-1].length());
        for(int i=0;i<len;i++){
            if(strs[0][i] == strs[n-1][i]){
                ans = ans + strs[0][i];
            }else{
                break;
            }
        }
        return ans;
    }
};