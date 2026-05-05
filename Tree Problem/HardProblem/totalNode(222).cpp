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
    int HeightLeft(TreeNode* node){
        if(!node) return 0;

        return 1 + HeightLeft(node -> left);
    }

    int HeightRight(TreeNode* node){
        if(!node) return 0;

        return 1 + HeightRight(node -> right);
    }

    int fun(TreeNode* node){
        if(!node) return 0;

        int leftHeight = HeightLeft(node);
        int rightHeight = HeightRight(node);

        if(leftHeight == rightHeight) return pow(2, leftHeight) - 1;

        return 1 + fun(node -> left) + fun(node -> right);
    }
    // int fun(TreeNode* node){
    //     if(!node) return 0;

    //     return 1 + fun(node -> left) + fun(node -> right);
    // }

public:
    int countNodes(TreeNode* root) {
        return fun(root);
    }
};