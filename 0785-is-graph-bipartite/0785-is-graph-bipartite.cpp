class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = 0;
        for(auto v:graph){
            for(auto val:v){
                n = max(val,n);
            }
        }
        n++;

        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                set<int> s1;
                set<int> s2;
                queue<int> q;
                q.push(i);
                s1.insert(i);
                visited[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    int number;
                    if(s1.count(node)) number = 1;
                    if(s2.count(node)) number = 2;

                    for(int neigh:graph[node]){
                        if(number == 1){
                            if(s1.count(neigh)) return false;
                            if(s2.count(neigh) == 0 && visited[neigh] == 0){
                                s2.insert(neigh);
                                q.push(neigh);
                                visited[neigh] = 1;
                            }
                        }
                        else{
                            if(s2.count(neigh)) return false;
                            if(s1.count(neigh) == 0 && visited[neigh] == 0){
                                s1.insert(neigh);
                                q.push(neigh);
                                visited[neigh] = 1;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};