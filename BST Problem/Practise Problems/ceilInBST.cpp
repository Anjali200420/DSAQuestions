class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        
        Node* cur = root;
        while(cur){
            if(cur -> data == x) return x;
            
            if(cur -> data > x){
                ans = cur -> data;
                cur = cur -> left;
            }
            else if(cur -> data < x){
                cur = cur -> right;
            }
        }
        
        return ans;
    }
};
