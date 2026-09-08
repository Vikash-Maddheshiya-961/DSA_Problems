class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        vector<int> mp(26,0);
        for(char ch:tasks){
            mp[ch-'A']++;
        }
        priority_queue<int> pq;

        for(int i=0;i<26;i++){
            if(mp[i]!=0){
                pq.push(mp[i]);
            }
        }
        vector<int> v;

        int timer = k + 1;
        int count = 0;

        while(!pq.empty() || v.size()!=0){
            if(!pq.empty()){
                int freq = pq.top()-1;
                pq.pop();
                if(freq!=0) v.push_back(freq);
            }

            timer--;

            if(timer == 0){
                for(int freq:v){
                    pq.push(freq);
                }
                v.clear();
                count += k+1;
                timer = k + 1;
            }
        }
        count += (k+1)-timer;
        return count;
    }
};