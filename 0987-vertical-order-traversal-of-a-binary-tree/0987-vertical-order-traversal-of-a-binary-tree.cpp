/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        unordered_map<int,vector<int>> mp;
        int s_idx = 0;
        int e_idx = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            vector<pair<int,int>> v1;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                int c = q.front().second;
                q.pop();
                if(c < s_idx) s_idx = c;
                else if(c > e_idx) e_idx = c;

                if(mp.find(c) == mp.end()){
                    vector<int> v;
                    mp[c] = v;
                }

                v1.push_back({temp->val,c});

                if(temp->left) q.push({temp->left,c-1});
                if(temp->right) q.push({temp->right,c+1});
            }
            sort(v1.begin(),v1.end());
            for(int i=0;i<v1.size();i++){
                mp[v1[i].second].push_back(v1[i].first);
            }
        } 

        for(int i=s_idx;i<=e_idx;i++){
            ans.push_back(mp[i]);
        }

        return ans;
    }
};