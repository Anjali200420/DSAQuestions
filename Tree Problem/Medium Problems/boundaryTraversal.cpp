/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    void leftNode(Node *node, Node* root, vector<int>& ans){
        if(!node) return;
        if(!node -> left && !node -> right) return;
        
        ans.push_back(node -> data);
        if(node -> left) leftNode(node -> left, root, ans);
        else if(node != root) leftNode(node -> right, root, ans);
    }
    
    void leafNode(Node* node, vector<int>& ans){
        if(!node) return;
        if(!node -> left && !node -> right){
            ans.push_back(node -> data);
            return;
        }
        
        leafNode(node -> left, ans);
        leafNode(node -> right, ans);
    }
    
    void rightNode(Node* node, vector<int>& rightN){
        if(!node) return;
        if(!node -> left && !node -> right) return;
        
        rightN.push_back(node -> data);
        if(node -> right) rightNode(node -> right, rightN);
        else rightNode(node -> left, rightN);
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        if(root == NULL) return {};
        
        vector<int> ans;
        leftNode(root, root, ans);
        leafNode(root, ans);
        
        vector<int> rightN;
        rightNode(root -> right, rightN);
        
        reverse(rightN.begin(), rightN.end());
        for(auto it : rightN){
            ans.push_back(it);
        }
        
        return ans;
    }
};