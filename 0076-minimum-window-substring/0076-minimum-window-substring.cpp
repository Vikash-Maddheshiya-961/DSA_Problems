class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<int> mp(256,0);
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }

        int l = 0;
        int r = 0;

        int count = 0;
        int min_len = 1e9;
        int min_idx = -1;
        while(r < n){
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;

            while(count == m){
                if(r-l+1 < min_len){
                    min_len = r-l+1;
                    min_idx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
            }

            r++;
        }

        return min_idx == -1 ? "" : s.substr(min_idx,min_len);
    }
};