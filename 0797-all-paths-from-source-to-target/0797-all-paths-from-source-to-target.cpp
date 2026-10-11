class Solution {
private:
    void dfs(vector<vector<int>>& adj,vector<vector<int>>& allpaths,vector<int>& currpath,int& target,int node){
        currpath.push_back(node);

        if(node == target){
            allpaths.push_back(currpath);
            currpath.pop_back();
            return;
        }
        
        for(auto neigh:adj[node]){
            dfs(adj,allpaths,currpath,target,neigh);
        }

        currpath.pop_back();
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> allpaths;
        vector<int> currpath;

        int target = V-1;

        dfs(graph,allpaths,currpath,target,0);

        return allpaths;
    }
};