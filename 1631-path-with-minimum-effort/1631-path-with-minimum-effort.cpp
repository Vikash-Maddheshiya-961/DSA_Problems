class Solution {
private:
    typedef pair<int,pair<int,int>> pip;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;

        priority_queue<pip,vector<pip>,greater<pip>> pq;
        pq.push({0,{0,0}});

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return diff;

            for(int k=0;k<4;k++){
                int new_row = row + dx[k];
                int new_col = col + dy[k];
                
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m){
                    int curr_diff = abs(heights[new_row][new_col] - heights[row][col]);
                    int new_effort = max(diff,curr_diff);
                    if(new_effort < dist[new_row][new_col]){
                        dist[new_row][new_col] = new_effort;
                        pq.push({dist[new_row][new_col],{new_row,new_col}});
                    }
                }
            }
        }

        return -1;
    }
};