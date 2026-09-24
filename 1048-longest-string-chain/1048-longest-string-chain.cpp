class Solution {
public:
    bool diffBy1(string &s1,string &s2){
        int n1 = s1.length();
        int n2 = s2.length();
        if(n2 != n1 + 1){
            return false;
        }
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(s1[i] != s2[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }

        if(i == n1) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string &s1,string &s2){
            return s1.length() < s2.length();
        });
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(diffBy1(words[j],words[i]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};