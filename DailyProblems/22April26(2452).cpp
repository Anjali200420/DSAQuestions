class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        set<string> st;

        for(auto it1 : queries){
            string word1 = it1;

            for(auto it2 : dictionary){
                string word2 = it2;

                int noOfEdits = 0;
                for(int ind = 0; ind < word1.length(); ind++){
                    if(word1[ind] != word2[ind]) noOfEdits++;
                }

                if(noOfEdits <= 2) st.insert(word1);
            }
        }
        

        vector<string> ans;
        for(auto it : queries){
            if(st.find(it) != st.end()) ans.push_back(it);
        }

        return ans;
    }
};