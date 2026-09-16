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
    TreeNode* solve(vector<int>& v,int ub){
        if(idx >= v.size() || v[idx] > ub) return NULL;
        
        TreeNode* root = new TreeNode(v[idx]);
        idx++;
        root->left = solve(v,root->val);
        root->right = solve(v,ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,INT_MAX);
    }
};