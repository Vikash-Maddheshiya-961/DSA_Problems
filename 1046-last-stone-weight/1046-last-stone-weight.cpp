class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(int w:stones) pq.push(w);

        while(!pq.empty()){
            int w1 = pq.top();
            pq.pop();
            if(pq.empty()){
                return w1;
            }
            int w2 = pq.top();
            pq.pop();

            if(w1 == w2) continue;
            pq.push(abs(w1-w2));
        }

        return 0;
    }
};