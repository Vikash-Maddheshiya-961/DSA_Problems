class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = 0;
        for(auto v:graph){
            for(auto val:v){
                n = max(n,val);
            }
        }
        n++;

        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int neigh:graph[node]){
                        if(color[neigh] == -1){
                            q.push(neigh);
                            color[neigh] = !color[node];
                        }
                        else if(color[neigh] == color[node]) return false;
                    }
                }
            }
        }

        return true;
    }
};