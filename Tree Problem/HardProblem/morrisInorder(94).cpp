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
        if(root == NULL) return {};

        vector<int> inorder;
        TreeNode* cur = root;

        while(cur){
            if(!cur -> left){
                inorder.push_back(cur -> val);
                cur = cur -> right;
            }
            else{
                TreeNode* temp = cur -> left;

                while(temp -> right && temp -> right != cur){
                    temp = temp -> right;
                }

                if(temp -> right == cur){
                    inorder.push_back(cur -> val);
                    cur = cur -> right;

                    temp -> right = NULL;
                }
                else{
                    temp -> right = cur;
                    cur = cur -> left;
                }
            }
        }

        return inorder;
    }
};