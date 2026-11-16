class Solution {
public:
    int res[1001][1001];
    int solve(string &text1,string &text2,int i,int j){
        if(i < 0 || j < 0) return 0;

        if(res[i][j] != -1) return res[i][j];

        if(text1[i] == text2[j]) return res[i][j] = 1 + solve(text1,text2,i-1,j-1);

        return res[i][j] = max(solve(text1,text2,i-1,j),solve(text1,text2,i,j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        memset(res,-1,sizeof(res));
        
        return solve(text1,text2,n-1,m-1);
    }
};