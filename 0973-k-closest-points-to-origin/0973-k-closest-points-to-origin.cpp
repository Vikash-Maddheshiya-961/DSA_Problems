class Solution {
public:
    typedef pair<int,pair<int,int>> pip;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pip> pq; // maxheap

        for(auto v:points){
            int x = v[0];
            int y = v[1];
            int dist = x*x + y*y;
            pq.push({dist,{x,y}});
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            pair<int,int> cord = pq.top().second;
            int x = cord.first;
            int y = cord.second;
            pq.pop();
            ans.push_back({x,y});
        }

        return ans;
    }
};