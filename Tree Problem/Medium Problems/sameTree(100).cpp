class Solution {
private:
    bool fun(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;

        return (node1 -> val == node2 -> val && fun(node1 -> left, node2 -> left) && fun(node1 -> right, node2 -> right));
    }
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p, q);
    }
};