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
        if(!root){
            return temp;
        }
        TreeNode* ptr = root;
        while(ptr){
            if(val < ptr->val){
                if(ptr->left) ptr = ptr->left;
                else {
                    ptr->left = temp;
                    break;
                }
            }
            else{
                if(ptr->right) ptr = ptr->right;
                else {
                    ptr->right = temp;
                    break;
                }
            }
        }

        return root;
    }
};