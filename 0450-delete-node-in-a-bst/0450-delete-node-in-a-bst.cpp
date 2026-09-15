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
    int findsucc(TreeNode* curr){
        while(curr->left) curr = curr -> left;
        return curr->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(key < root -> val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root -> val){
            root -> right = deleteNode(root->right,key);
        }
        else{
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
            }
            else{
                int successor = findsucc(root->right);
                root -> val = successor;
                root->right = deleteNode(root->right,successor);
            }
        }
        return root;
    }
};