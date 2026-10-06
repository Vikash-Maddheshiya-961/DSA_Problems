class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int node=0;node<n;node++){
            for(int neigh:graph[node]){
                adj[neigh].push_back(node);
            }
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

        sort(topo.begin(),topo.end());

        return topo;
    }
};