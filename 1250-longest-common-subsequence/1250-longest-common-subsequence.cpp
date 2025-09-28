class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        vector<vector<int>> L(l1+1,vector<int>(l2+1,0));
        for(int i = 1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(s1[i-1] == s2[j-1]){
                    L[i][j] = 1+L[i-1][j-1];
                }else{
                    L[i][j] = max(L[i-1][j],L[i][j-1]);
                }
            }
        }
        return L[l1][l2];
    }
};