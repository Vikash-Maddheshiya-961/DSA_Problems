class Solution {
public:
    int res[1001][1001];
    bool is_palindrome(string &s,int i,int j){
        if(i >= j) return true;
        if(res[i][j] != -1) return res[i][j];
        if(s[i] == s[j]) return res[i][j] = is_palindrome(s,i+1,j-1);

        return res[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.length();

        int maxi = 0;
        int si;

        memset(res,-1,sizeof(res));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len = j-i+1;
                if(len <= maxi) continue;
                if(is_palindrome(s,i,j)){
                    maxi = len;
                    si = i;
                }
            }
        }

        return s.substr(si,maxi);
    }
};