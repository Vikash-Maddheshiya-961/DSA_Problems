class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int e = prerequisites.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<e;i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        vector<int> inorder(n,0);
        for(auto node:adj){
            for(auto neigh:node){
                inorder[neigh]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inorder[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto neigh:adj[node]){
                inorder[neigh]--;
                if(inorder[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        if(topo.size() != n) return {};

        return topo;
    }
};