class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> idx(26);
        vector<int> seen(26,0);

        for(int i=0;i<n;i++){
            idx[s[i]-'a'] = i;
        }

        string ans;

        for(int i=0;i<n;i++){
            char ch = s[i];
            if(seen[ch - 'a']) continue;

            while(ans.length()!=0 && ans.back() > ch && idx[ans.back()-'a'] > i){
                seen[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(ch);
            seen[ch-'a'] = 1;
        }
        
        return ans;
    }
};