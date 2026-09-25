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
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            int min_cuts = 1e9;
            for(int j=i;j<n;j++){
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