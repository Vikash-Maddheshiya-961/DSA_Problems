class Solution {
public:
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+2,0);
        for(int i=n;i>=0;i--){
            if(i == n){
                dp[n] = 0;
                continue;
            }
            int min_cuts = 1e9;
            for(int j=n;j>=i;j--){
                if(ispalindrome(s,i,j)){
                    int curr_cuts = 1 + dp[j+1];
                    min_cuts = min(min_cuts,curr_cuts);
                }
            }
            dp[i] = min_cuts;
        }
        return dp[0] - 1;
    }
};