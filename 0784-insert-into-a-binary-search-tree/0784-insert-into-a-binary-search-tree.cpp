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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if(root == NULL) return temp;
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        while(curr!=NULL){
            prev = curr;
            if(val < curr->val){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        if(val<prev->val){
            prev->left = temp;
        }else{
            prev->right = temp;
        }
        return root;
    }
};