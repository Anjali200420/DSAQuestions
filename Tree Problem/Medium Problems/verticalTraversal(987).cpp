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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mpp;

        q.push({root, {0, 0}});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();

            mpp[col][row].insert(node -> val);

            if(node -> left){
                q.push({node -> left, {row+1, col-1}});
            }
            
            if(node -> right){
                q.push({node -> right, {row+1, col+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto it1 : mpp){
            vector<int> col;
            for(auto it2 : it1.second){
                col.insert(col.end(), it2.second.begin(), it2.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};