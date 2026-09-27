class Solution {
public:
    int res[501][501];
    int solve(string& s1,string& s2,int i,int j){
        if(i < 0 && j < 0) return 0;
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(res[i][j] != -1) return res[i][j];
        if(s1[i] == s2[j]) return res[i][j] = solve(s1,s2,i-1,j-1);

        return res[i][j] = 1 + min(solve(s1,s2,i-1,j),solve(s1,s2,i,j-1));
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        memset(res,-1,sizeof(res));
        return solve(word1,word2,m-1,n-1);
    }
};