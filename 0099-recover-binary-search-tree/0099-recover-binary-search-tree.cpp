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
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;
    void inorder(TreeNode* curr){
        if(curr == NULL) return;

        inorder(curr->left);

        if(prev && curr->val < prev->val){
            if(first == NULL){
                first = prev;
                middle = curr;
            }
            else last = curr;
        }

        prev = curr;

        inorder(curr->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);

        return;
    }
};