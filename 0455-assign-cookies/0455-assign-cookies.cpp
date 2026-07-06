class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int nch = g.size();
        int nco = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int maxi = 0;
        int i=0, j=0;
        while(i<nch && j<nco){
            if(g[i] <= s[j]){
                maxi++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return maxi;
    }
};