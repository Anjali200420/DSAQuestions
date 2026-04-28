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
    int fun(TreeNode* node){
        if(node == nullptr) return 0;

        return 1 + max(fun(node -> left), fun(node -> right));
    }
    
public:
    int maxDepth(TreeNode* root) {
        return fun(root);
    }
};