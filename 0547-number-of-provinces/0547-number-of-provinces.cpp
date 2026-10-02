class Solution {
public:
    void bfs(vector<vector<int>>& adj,int s,vector<int>& visited){
        queue<int> q;
        q.push(s);
        visited[s] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neigh:adj[node]){
                if(visited[neigh] == 0){
                    q.push(neigh);
                    visited[neigh] = 1;
                }
            }
        }

        return;
    }
    void solve(vector<vector<int>>& adj,int &count,int &n){
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                count++;
                bfs(adj,i,visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        solve(adj,count,n);
        return count;
    }
};