class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);

        for(auto ch:tasks){
            mp[ch-'A']++;
        }

        priority_queue<int> pq;

        for(int i=0;i<26;i++){
            if(mp[i] != 0){
                pq.push(mp[i]);
            }
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> v;

            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq = pq.top()-1;
                    pq.pop();
                    v.push_back(freq);
                }
                else break;
            }

            for(int freq:v){
                if(freq > 0) pq.push(freq);
            }

            if(!pq.empty()){
                time += (n+1);
            }
            else{
                time += v.size();
            }
        }

        return time;
    }
};