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
    bool solve(TreeNode* root,long long lb,long long ub){
        if(root == NULL) return true;

        if(root->val >= lb && root->val <= ub){
            return solve(root->left,lb,(long long)root->val-1) && solve(root->right,(long long)root->val+1,ub);
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};