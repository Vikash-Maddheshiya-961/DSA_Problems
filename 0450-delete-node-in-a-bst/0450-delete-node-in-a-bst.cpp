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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }else{
            if(root->left == NULL){
                TreeNode* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }else{
                int val = min_val(root->right);
                root->val = val;
                root->right = deleteNode(root->right,val);
            }
        }
        return root;
    }
    int min_val(TreeNode* temp){
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp->val;
    }
};