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
private:
    bool ismirror(TreeNode* p1,TreeNode*p2){
        if(p1 == NULL && p2 == NULL) return true;

        if(p1 == NULL || p2 == NULL) return false;

        return (p1->val == p2->val) && ismirror(p1->left,p2->right) && ismirror(p1->right,p2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        return ismirror(root->left,root->right);
    }
};