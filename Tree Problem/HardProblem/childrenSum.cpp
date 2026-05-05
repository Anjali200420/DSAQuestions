/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  private:
    int fun(Node* node){
        if(!node) return -1;
        
        int left = fun(node -> left);
        int right = fun(node -> right);
        
        if(left == -2 || right == -2) return -2;
        
        if((left == -1 && right == -1) || (node -> data == max(0, left) + max(0, right))) return node -> data;
        
        return -2;
    }
    
  public:
    bool isSumProperty(Node *root) {
        // code here
        return fun(root) == -2 ? false : true;  
    }
};