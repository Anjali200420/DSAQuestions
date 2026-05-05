class Solution {
private:
    int ans = INT_MIN;

    int fun(TreeNode* node){
        if(node == nullptr) return 0;

        int leftSum = max(0, fun(node -> left));
        int rightSum = max(0, fun(node -> right));

        ans = max(ans, node -> val + leftSum + rightSum);

        return (node -> val + max(leftSum, rightSum));
    }

public:
    int maxPathSum(TreeNode* root) {
        fun(root);

        return ans;
    }
};