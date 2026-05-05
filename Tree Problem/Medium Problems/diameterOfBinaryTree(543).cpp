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
//     int ans = INT_MIN;
//     int maxDepth(TreeNode* node){
//         if(node == nullptr) return 0;

//         return 1 + max(maxDepth(node -> left), maxDepth(node -> right));
//     }

//     void fun(TreeNode* node){
//         if(node == nullptr) return;

//         int lh = maxDepth(node -> left);
//         int rh = maxDepth(node -> right);

//         ans = max(ans, lh + rh);

//         fun(node -> left);
//         fun(node -> right);
//     }

// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         fun(root);

//         return ans;
//     }
// };

class Solution {
private:
    int ans = INT_MIN;
    int fun(TreeNode* node){
        if(node == nullptr) return 0;

        int lh = fun(node -> left);
        int rh = fun(node -> right);

        ans = max(ans, lh + rh);

        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);

        return ans;
    }
};