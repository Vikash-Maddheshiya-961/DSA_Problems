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
    TreeNode* solve(vector<int>& v,int ub,int &idx){
        if(idx >= v.size() || v[idx] > ub) return NULL;

        TreeNode* root = new TreeNode(v[idx++]);
        root->left = solve(v,root->val,idx);
        root->right = solve(v,ub,idx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return solve(preorder,INT_MAX,idx);
    }
};