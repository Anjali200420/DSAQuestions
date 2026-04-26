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
    void fun(TreeNode* node, vector<int>& postorder){
        if(node == NULL) return;
        
        fun(node -> left, postorder);
        fun(node -> right, postorder);

        postorder.push_back(node -> val);
    }

public:
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> postorder;

    //     fun(root, postorder);
    //     return postorder;
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     if(root == NULL) return {};

    //     stack<TreeNode*> st1;
    //     stack<TreeNode*> st2;

    //     st1.push(root);
    //     while(!st1.empty()){
    //         TreeNode* node = st1.top();
    //         st1.pop();

    //         st2.push(node);
    //         if(node -> left) st1.push(node -> left);
    //         if(node -> right) st1.push(node -> right);
    //     }

    //     vector<int> postorder;
    //     while(!st2.empty()){
    //         postorder.push_back(st2.top() -> val);
    //         st2.pop();
    //     }

    //     return postorder;
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector<int> postorder;
        stack<TreeNode*> st;

        TreeNode* cur = root;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur -> left;
            }
            else{
                TreeNode* temp = st.top() -> right;

                if(temp){
                    cur = temp;
                }
                else{
                    temp = st.top();
                    postorder.push_back(temp -> val);

                    st.pop();

                    while(!st.empty() && temp == st.top() -> right){
                        temp = st.top();
                        postorder.push_back(temp -> val);

                        st.pop();
                    }
                }
            }
        }

        return postorder;
    }
};