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
    void fun(TreeNode* node, vector<int>& preorder){
        if(node == NULL) return;

        preorder.push_back(node -> val);
        fun(node -> left, preorder);
        fun(node -> right, preorder);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<int> preorder;
        TreeNode* cur = root;

        while(cur){
            if(!cur -> left){
                preorder.push_back(cur -> val);
                cur = cur -> right;
            }
            else{
                TreeNode* temp = cur -> left;

                while(temp -> right && temp -> right != cur) temp = temp -> right;

                if(temp -> right == cur){
                    cur = cur -> right;
                    temp -> right = NULL;
                }
                else{
                    preorder.push_back(cur -> val);
                    temp -> right = cur;
                    cur = cur -> left;
                }
            }
        }

        return preorder;
    }
};