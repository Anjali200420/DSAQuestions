/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:  
    bool findPath(TreeNode* node, TreeNode* target, vector<TreeNode*>& temp, vector<TreeNode*>& path){
        if(!node) return false;
        
        temp.push_back(node);

        if(node == target){
            path = temp;
            return true;
        }

        if(findPath(node -> left, target, temp, path)) return true;

        if(findPath(node -> right, target, temp, path)) return true;

        temp.pop_back();

        return false;
    }

    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == nullptr || node == p || node == q) return node;

        TreeNode* left = lca(node -> left, p, q);
        TreeNode* right = lca(node -> right, p, q);

        if(!left) return right;
        else if(!right) return left;
        return node;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, temp1;
        findPath(root, p, temp1, pPath);

        vector<TreeNode*> qPath, temp2;
        findPath(root, q, temp2, qPath);

        TreeNode* ans;
        for(auto it1 : pPath){
            for(auto it2 : qPath){
                if(it1 == it2) ans = it1;
            }
        }

        return ans;

        return lca(root, p, q);
    }
};