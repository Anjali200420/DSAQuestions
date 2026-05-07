/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        
        Node* cur = root;
        while(cur){
            if(cur -> data == k) return k;
            
            if(cur -> data < k){
                ans = cur ->data;
                cur = cur -> right;
            }
            else if(cur -> data > k){
                cur = cur -> left;
            }
        }
        
        return ans;
    }
};