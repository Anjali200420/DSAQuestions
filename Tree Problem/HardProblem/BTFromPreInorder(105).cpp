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
    TreeNode* fun(int preBeg, int preEnd, int inBeg, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preBeg > preEnd || inBeg > inEnd) return NULL;

        int val = preorder[preBeg];
        TreeNode* node = new TreeNode(val);

        int ind = inBeg;
        for(int i = inBeg; i <= inEnd; i++){
            if(inorder[i] == val){
                ind = i;
                break;
            }
        }

        node -> left = fun(preBeg + 1, preBeg + (ind - inBeg), inBeg, ind-1, preorder, inorder);
        node -> right = fun(preBeg + (ind - inBeg) + 1, preEnd, ind+1, inEnd, preorder, inorder);

        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        return fun(0, n-1, 0, n-1, preorder, inorder);
    }
};