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
    void inorder(TreeNode* root,vector<int>&v){
        if(root == NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        int n = v.size();
        for(int i=0;i<n;i++){
            int target = k - v[i];
            for(int j=i+1;j<n;j++){
                if(v[j] == target) return true;
            }
        }
        return false;
    }
};