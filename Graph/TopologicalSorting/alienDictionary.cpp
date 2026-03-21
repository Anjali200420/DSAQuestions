class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        
        for(auto word : words){
            for(char ch : word){
                present[ch-'a'] = true;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++){
            string first = words[i];
            string second = words[i+1];
            
            int len = min(first.size(), second.size());
            
            if(first.size() > second.size() && first.substr(0, len) == second)
                return "";
                
            for(int ind = 0; ind < len; ind++){
                if(first[ind] != second[ind]){
                    adj[first[ind]-'a'].push_back(second[ind]-'a');
                    indegree[second[ind] - 'a']++;
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i = 0; i < 26; i++){
            if(present[i] & indegree[i] == 0) q.push(i);
        }
        
        string ans = "";
        while(!q.empty()){
            int ch = q.front(); 
            q.pop();
            
            ans += ch + 'a';
            
            for(auto it : adj[ch]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        
        if(ans.size() == count(present.begin(), present.end(), true)) return ans;
        return "";
    }
};