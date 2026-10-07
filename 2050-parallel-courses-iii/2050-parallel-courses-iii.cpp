class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        for(auto edge:relations){
            int u = edge[0]-1;
            int v = edge[1]-1;
            adj[u].push_back(v);
        }

        vector<int> inorder(n,0);
        for(auto node:adj){
            for(auto neigh:node){
                inorder[neigh]++;
            }
        }

        queue<int> q;
        vector<int> max_time(n,0);
        for(int i=0;i<n;i++){
            if(inorder[i] == 0){
                q.push(i);
                max_time[i] = time[i];
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            int t = max_time[node];

            for(auto neigh:adj[node]){
                int tn = time[neigh];
                max_time[neigh] = max(max_time[neigh],t+tn);
                inorder[neigh]--;
                if(inorder[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        int months = 0;
        for(int i=0;i<n;i++){
            months = max(max_time[i],months);
        }

        return months;
    }
};