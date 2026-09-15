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
    bool flag = true;
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lefth = height(root->left);
        int righth = height(root->right);
        int diff = abs(lefth-righth);
        if(diff > 1) flag = false;

        return 1 + max(lefth,righth);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return flag;
    }
};