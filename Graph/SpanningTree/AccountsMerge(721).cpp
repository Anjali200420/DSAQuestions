class DisjointSet {
    private:
        vector<int> rank, parent;

    public:
        DisjointSet(int n){
            rank.resize(n, 0);
            parent.resize(n);

            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int findUlParent(int x){
            if(parent[x] == x) return x;

            return parent[x] = findUlParent(parent[x]);
        }

        void findUnion(int x, int z){
            int ulp_x = findUlParent(x);
            int ulp_z = findUlParent(z);

            if(rank[ulp_x] > rank[ulp_z]) parent[ulp_z] = ulp_x;
            else if(rank[ulp_x] < rank[ulp_z]) parent[ulp_x] = ulp_z;
            else{
                parent[ulp_z] = ulp_x;
                rank[ulp_x]++;
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string, int> mpp;
        DisjointSet ds(n);

        for(int account = 0; account < n; account++){
            for(int email = 1; email < accounts[account].size(); email++){
                if(mpp.find(accounts[account][email]) == mpp.end()){
                    mpp[accounts[account][email]] = account;
                }
                else{
                    ds.findUnion(account, mpp[accounts[account][email]]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto it : mpp){
            string mail = it.first;

            int ulp_parent = ds.findUlParent(it.second);
            mergedMail[ulp_parent].push_back(it.first);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergedMail[i].size() == 0) continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mergedMail[i].begin(), mergedMail[i].end());
            for(int j = 0; j < mergedMail[i].size(); j++){
                temp.push_back(mergedMail[i][j]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};