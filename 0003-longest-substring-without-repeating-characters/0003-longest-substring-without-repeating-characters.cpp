class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> mp(256,0);

        int l = 0;
        int r = 0;

        int max_len = 0;

        while(r < n){
            int ch2 = s[r];
            int idx2 = int(ch2);
            while(mp[idx2] != 0){
                int ch1 = s[l];
                int idx1 = int(ch1);
                mp[idx1]--;
                l++;
            }

            mp[idx2]++;
            max_len = max(max_len,r-l+1);
            r++;
        }

        return max_len;
    }
};