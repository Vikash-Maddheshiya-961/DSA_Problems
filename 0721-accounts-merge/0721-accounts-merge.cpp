class DisjointSet{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DisjointSet(int n){
            rank.assign(n,0);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        int find(int u){
            if(parent[u] == u){
                return u;
            }

            return parent[u] = find(parent[u]);
        }

        void Union(int u,int v){
            int a = find(u);
            int b = find(v);

            if(a == b) return;

            if(rank[a] < rank[b]){
                parent[a] = b;
            }
            else if(rank[b] < rank[a]){
                parent[b] = a;
            }
            else{
                parent[b] = a;
                rank[a]++;
            }

            return;
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int> mp;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(mp.find(email) != mp.end()){
                    ds.Union(mp[email],i);
                }
                else{
                    mp[email] = i;
                }
            }
        }

        vector<vector<string>> temp(n);

        for(auto p:mp){
            string email = p.first;
            int idx = p.second;

            int parent = ds.find(idx);
            temp[parent].push_back(email);
        }

        for(int i=0;i<n;i++){
            sort(temp[i].begin(),temp[i].end());
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            string name = accounts[i][0];

            if(temp[i].size() != 0){
                temp[i].insert(temp[i].begin(),name);
                ans.push_back(temp[i]);
            }
        }

        return ans;

    }
};