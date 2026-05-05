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
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        long long ans = INT_MIN;
        while(!q.empty()){
            int sz = q.size();
            long long min_ind = q.front().second;
            
            long long start = -1, end = -1;
            for(int i = 1; i <= sz; i++){
                TreeNode* node = q.front().first;
                int pos = q.front().second;

                long long curInd = pos - min_ind;

                q.pop();

                if(i == 1) start = pos;
                if(i == sz) end = pos;

                if(node -> left){
                    q.push({node -> left, 2*curInd + 1});
                }

                if(node -> right){
                    q.push({node -> right, 2*curInd + 2});
                }
            }
            ans = max(ans, (end - start + 1));
        }

        return ans;
    }
};