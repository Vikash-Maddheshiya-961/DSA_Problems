class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        queue<int> q;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
            
            if(mp[s[i]] == 1){
                q.push(i);
            }

            while(!q.empty() && mp[s[q.front()]] > 1){
                q.pop();
            }
        }

        if(!q.empty()){
            return q.front();
        }

        return -1;
    }
};