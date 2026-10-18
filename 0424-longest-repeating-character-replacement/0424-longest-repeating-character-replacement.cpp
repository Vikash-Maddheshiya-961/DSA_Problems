class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> mp(26,0);
        int max_len = 0;
        int l = 0;
        int r = 0;
        int max_freq = 0;
        while(r < n){
            mp[s[r]-'A']++;

            max_freq = max(max_freq,mp[s[r]-'A']);

            while((r-l+1)-max_freq > k){
                mp[s[l]-'A']--;
                max_freq = 0;
                for(int i=0;i<26;i++){
                    max_freq = max(max_freq,mp[i]);
                }
                l++;
            }

            if((r-l+1) - max_freq <= k){
                max_len = max(max_len,r-l+1);
            }

            r++;
        }

        return max_len;
    }
};