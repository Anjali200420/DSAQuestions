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
  public:
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*, int>> q;
        map<int, int> mpp;
        
        q.push({root, 0});
        while(!q.empty()){
            Node* node = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            if(mpp.find(col) == mpp.end()){
                mpp[col] = node -> data;
            }
            
            if(node -> left) q.push({node -> left, col-1});
            if(node -> right) q.push({node -> right, col+1});
        }
        
        vector<int> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};