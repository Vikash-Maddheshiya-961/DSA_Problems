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
class bstiterator{
private:
    void push1(TreeNode* curr){
        while(curr){
            s1.push(curr);
            curr = curr -> left;
        }
        return;
    }
    void push2(TreeNode* curr){
        while(curr){
            s2.push(curr);
            curr = curr -> right;
        }
        return;
    }
public:
    stack<TreeNode*> s1;// next
    stack<TreeNode*> s2;// before
    bstiterator(TreeNode* root){
        push1(root);
        push2(root);
    }
    int next(){
        TreeNode* curr = s1.top();
        s1.pop();
        push1(curr->right);
        return curr->val;
    }
    int before(){
        TreeNode* curr = s2.top();
        s2.pop();
        push2(curr->left);
        return curr->val;
    }
    bool isnext(){
        return !s1.empty();
    }
    bool isbefore(){
        return !s2.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bstiterator bst(root);
        int i = bst.next();
        int j = bst.before();
        while(i<j){
            int sum = i+j;
            if(sum == k) return true;
            else if(sum < k){
                i = bst.next();
            }
            else j = bst.before();
        }

        return false;
    }
};