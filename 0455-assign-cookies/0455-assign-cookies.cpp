class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int nch = g.size();
        int nco = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int maxi = 0;
        int j=0;
        for(int i=0;i<nch;i++){
            while(j<nco){
                if(g[i] <= s[j]){
                    maxi++;
                    j++;
                    break;
                }
                j++;
            }
        }
        return maxi;
    }
};