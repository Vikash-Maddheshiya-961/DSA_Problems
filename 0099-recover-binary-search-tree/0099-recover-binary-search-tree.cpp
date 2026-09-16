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
    void inorder(TreeNode* root,vector<int> &v){
        if(root == NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        return;
    }
    void solve(TreeNode* root,vector<int> &v,int &idx){
        if(root == NULL) return;
        solve(root->left,v,idx);
        if(v[idx]!=root->val){
            root->val = v[idx++];
        }
        else idx++;
        solve(root->right,v,idx);
        return;
    }
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int idx = 0;
        solve(root,v,idx);
    }
};