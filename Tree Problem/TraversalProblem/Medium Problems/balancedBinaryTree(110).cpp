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
// class Solution {
// private:
//     int maxDepth(TreeNode* node){
//         if(node == nullptr) return 0;

//         return 1 + max(maxDepth(node -> left), maxDepth(node -> right));
//     }

//     bool fun(TreeNode* node){
//         if(node == nullptr) return true;

//         int lh = maxDepth(node -> left);
//         int rh = maxDepth(node -> right);

//         if(abs(lh - rh) > 1) return false;

//         return (fun(node -> left) && fun(node -> right));
//     }

// public:
//     bool isBalanced(TreeNode* root) {
//         return fun(root);
//     }
// };

class Solution {
private:
    int fun(TreeNode* node){
        if(node == nullptr) return 0;

        int lh = fun(node -> left);
        if(lh == -1) return -1;

        int rh = fun(node -> right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        return fun(root) == -1 ? false : true;
    }
};