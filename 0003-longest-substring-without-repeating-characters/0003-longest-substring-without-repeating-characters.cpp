class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> mp(256,0);

        int l = 0;
        int r = 0;

        int max_len = 0;

        while(r < n){
            while(mp[s[r]] != 0){
                mp[s[l]]--;
                l++;
            }

            mp[s[r]]++;
            max_len = max(max_len,r-l+1);
            r++;
        }

        return max_len;
    }
};