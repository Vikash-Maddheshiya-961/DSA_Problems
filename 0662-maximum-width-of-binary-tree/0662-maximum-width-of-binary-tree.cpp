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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxi = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            long long first;
            long long last;
            long long minidx = q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                long long idx = q.front().second - minidx;
                q.pop();

                if(i == 0) first = idx;
                if(i == size-1) last = idx;

                if(temp->left) q.push({temp->left,2*idx+1});
                if(temp->right) q.push({temp->right,2*idx+2});
            }
            maxi = max(maxi,last-first+1);
        }

        return maxi;
    }
};