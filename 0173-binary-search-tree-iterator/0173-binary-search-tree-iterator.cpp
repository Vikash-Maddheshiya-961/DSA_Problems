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
class BSTIterator {
private:
    void pushall(TreeNode* curr){
        while(curr){
            s.push(curr);
            curr = curr -> left;
        }
        return;
    }
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {// constructor
        pushall(root);
    }
    
    int next() {
        TreeNode* curr = s.top();
        s.pop();
        pushall(curr->right);
        return curr -> val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */