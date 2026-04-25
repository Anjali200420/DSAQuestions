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
    void fun(TreeNode* node, vector<int>& inorder){
        if(node == NULL) return;

        fun(node -> left, inorder);
        inorder.push_back(node -> val);
        fun(node -> right, inorder);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        fun(root, inorder);
        return inorder;
    }
};