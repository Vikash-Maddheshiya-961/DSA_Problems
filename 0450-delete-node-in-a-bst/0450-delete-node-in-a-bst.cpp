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
    int min_element(TreeNode* temp){
        while(temp -> left != NULL){
            temp = temp->left;
        }
        return temp->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            else if(root->left != NULL && root->right != NULL){
                int succ = min_element(root->right);
                root->val = succ;
                root->right = deleteNode(root->right,succ);
            }
            else if(root->left == NULL && root->right != NULL){
                return root->right;
            }
            else{
                return root->left;
            }
        }

        return root;
    }
};