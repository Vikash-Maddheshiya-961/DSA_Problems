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
    int idx = 0; 
    int n;
    TreeNode* solve(vector<int> &preorder,int ub){
        if(idx >= n || preorder[idx] > ub) return NULL;

        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = solve(preorder,root->val);
        root->right = solve(preorder,ub);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        return solve(preorder,INT_MAX);
    }
};