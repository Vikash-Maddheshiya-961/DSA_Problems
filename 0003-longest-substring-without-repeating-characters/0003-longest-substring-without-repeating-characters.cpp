class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int max_len = 0;
        int l = 0;
        int r = 0;

        while(r < n){
            mp[s[r]]++;

            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }

            max_len = max(max_len,r-l+1);
            r++;
        }

        return max_len;
    }
};