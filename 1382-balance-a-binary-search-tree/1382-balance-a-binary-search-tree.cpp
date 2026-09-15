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
    vector<int> v;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return;
    }
    TreeNode* solve(int lo,int hi){
        if(lo > hi) return NULL;

        int mid = lo + (hi - lo) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = solve(lo,mid-1);
        root->right = solve(mid+1,hi);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return solve(0,v.size()-1);
    }
};