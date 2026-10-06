class Solution {
private:
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,vector<int>& pathvisited,vector<int>& check,int node){
        visited[node] = 1;
        pathvisited[node] = 1;

        check[node] = 0;
        for(int neigh:graph[node]){
            if(visited[neigh] == 0){
                if(dfs(graph,visited,pathvisited,check,neigh) == true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvisited[neigh] == 1){
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathvisited[node] = 0;

        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> check(n,0);

        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                dfs(graph,visited,pathvisited,check,i);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
             if(check[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};