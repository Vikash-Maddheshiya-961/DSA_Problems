class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        int e = prerequisites.size();
        for(int i=0;i<e;i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        
        vector<int> inorder(n,0);
        for(auto v:adj){
            for(int node:v){
                inorder[node]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inorder[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();

            for(int neigh:adj[node]){
                inorder[neigh]--;
                if(inorder[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        if(cnt != n) return false;

        return true;
    }
};