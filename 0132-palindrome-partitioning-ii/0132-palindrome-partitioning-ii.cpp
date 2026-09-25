class Solution {
public:
    int n;
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int res[2001];
    int solve(string &s,int i){
        if(i == n) return 0;
        if(res[i] != -1) return res[i];
        int min_cuts = 1e9;
        for(int j=i;j<n;j++){
            if(ispalindrome(s,i,j)){
                int curr_cuts = 1 + solve(s,j+1);
                min_cuts = min(min_cuts,curr_cuts);
            }
        }

        return res[i] = min_cuts;
    }
    int minCut(string s) {
        n = s.length();
        memset(res,-1,sizeof(res));
        return solve(s,0)-1;
    }
};