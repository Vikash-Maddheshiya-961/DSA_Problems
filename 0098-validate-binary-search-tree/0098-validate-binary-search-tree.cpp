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
    bool solve(TreeNode* root,long long lo,long long hi){
        if(root == NULL) return true;
        if(root->val >= lo && root->val <=hi){
            bool left = solve(root->left,lo,(long long)root->val-1);
            bool right = solve(root->right,(long long)root->val+1,hi);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,(long long)INT_MIN,(long long)INT_MAX);
    }
};