class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];
        string ans = "";
        sort(strs.begin(),strs.end());
        int len = min(strs[0].length(),strs[1].length());
        int i=0;
        while(i < len && strs[0][i]==strs[n-1][i]){
            ans += strs[0][i];
            i++;
        }
        return ans;
    }
};