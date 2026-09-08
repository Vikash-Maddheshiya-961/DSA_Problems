class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> mp(26,0);
        for(char ch:s){
            mp[ch - 'a']++;
        }

        priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>> temp;

        for(int i=0;i<26;i++){
            if(mp[i] > 0) pq.push({mp[i],i});
        }

        string ans;

        while(!pq.empty()){
            pair<int,int> p = pq.top();
            char ch = char(p.second + 'a');
            ans += ch;
            p.first--;
            pq.pop();
            if(temp.size()!=0){
                pq.push(temp.top());
                temp.pop();
            }
            if(p.first != 0) temp.push(p);
        }

        if(ans.length() != s.length()) return "";
        return ans;
    }
};