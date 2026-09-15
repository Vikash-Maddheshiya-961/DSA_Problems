/**
 * Definition for a binary tree curr.
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
        while(curr -> left) curr = curr -> left;
        return curr -> val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* temp = root;
        TreeNode* curr = NULL;
        TreeNode* prev = NULL;
        while(temp){
            if(key == temp->val){
                curr = temp;
                break;
            }
            prev = temp;
            if(key < temp->val) temp = temp -> left;
            else temp = temp -> right;
        }
        if(curr == NULL) return root;

        // no child

        if(!curr -> left && !curr -> right){
            if(prev == NULL) {
                delete curr;
                return NULL;
            }
            if(curr == prev ->left) prev -> left = NULL;
            else prev -> right = NULL;
            delete curr;
            return root;
        }

        // 1 child
        if(curr->left && !curr->right){
            if(prev == NULL){
                prev = curr -> left;
                curr -> left = NULL;
                delete curr;
                return prev;
            }

            if(curr == prev -> right){
                prev -> right = curr -> left;
            }
            else{
                prev -> left = curr -> left;
            }
            curr -> left = NULL;
            delete curr;
            return root;
        }

        if(!curr -> left && curr -> right){
            if(prev == NULL){
                prev = curr -> right;
                curr -> right = NULL;
                delete curr;
                return prev;
            }

            if(curr == prev->left){
                prev -> left = curr -> right;
            }else{
                prev -> right = curr -> right;
            }

            curr -> right = NULL;
            delete curr;
            return root;
        }

        // 2 child
        int successor = findsucc(curr->right);
        curr -> val = successor;
        curr -> right = deleteNode(curr->right, successor);

        return root;
    }
};