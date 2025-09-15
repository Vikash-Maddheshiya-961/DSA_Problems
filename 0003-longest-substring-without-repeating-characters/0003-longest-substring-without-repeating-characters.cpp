class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp(128);
        for(int i=0;i<128;i++){
            mp[i] = -1;
        }
        int n = s.size();
        int maxlen = 0;
        int left =0;
        for(int right=0;right<n;right++){
            if(mp[s[right]]!=-1){
                if(mp[s[right]]>=left)
                left = mp[s[right]]+1;
            }
            int len = right-left+1;
            maxlen = max(len,maxlen);
            mp[s[right]] = right;
        }
        return maxlen;
   }
};