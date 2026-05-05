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
    TreeNode* fun(int inBeg, int inEnd, int postBeg, int postEnd, vector<int>& inorder, vector<int>& postorder){
        if(inBeg > inEnd || postBeg > postEnd) return NULL;

        int val = postorder[postEnd];

        int ind = inBeg;
        for(int i = inBeg; i <= inEnd; i++){
            if(inorder[i] == val){
                ind = i; 
                break;
            }
        }

        TreeNode* node = new TreeNode(val);

        node -> left = fun(inBeg, ind-1, postBeg, postBeg + (ind - inBeg) - 1, inorder, postorder);
        node -> right = fun(ind+1, inEnd, postBeg + (ind - inBeg), postEnd - 1, inorder, postorder);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        return fun(0, n-1, 0, n-1, inorder, postorder);
    }
};