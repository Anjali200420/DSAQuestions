/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void markParents(Node* root, unordered_map<Node*, Node*>& parent){
        if(!root) return;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
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
    
    Node* findNode(Node* root, int target){
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node -> data == target) return node;
            
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        
        return NULL;
    }
    
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent;
        markParents(root, parent);
        
        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        
        Node* tar = findNode(root, target);
        
        q.push(tar);
        vis[tar] = true;
        
        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 1; i <= sz; i++){
                Node* node = q.front();
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
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
            
            ans++;
        }
        
        return ans;
    }
};