class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<int> mp(256,0);
        for(auto ch:t){
            mp[ch]++;
        }

        int count = 0;
        int min_len = INT_MAX;
        int start_idx = -1;

        int l = 0;
        int r = 0;

        while(r < n){
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;

            while(count == m){
                if((r-l+1) < min_len){
                    min_len = r-l+1;
                    start_idx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
            }

            r++;
        }

        return start_idx == -1 ? "" : s.substr(start_idx,min_len);
    }
};