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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        if(!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node -> left){
                q.push(node -> left);
                parent[node -> left] = node;
            }

            if(node -> right){
                q.push(node -> right);
                parent[node -> right] = node;
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis[target] = true;

        int dis = 0;
        while(!q.empty() && dis < k){
            dis++;

            int sz = q.size();

            for(int i = 1; i <= sz; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left && !vis[node -> left]){
                    q.push(node -> left);
                    vis[node -> left] = true;
                }

                if(node -> right && !vis[node -> right]){
                    q.push(node -> right);
                    vis[node -> right] = true;
                }

                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }

        return ans;
    }
};