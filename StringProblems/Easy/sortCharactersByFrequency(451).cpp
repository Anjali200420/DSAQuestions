class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;

        for(int ind = 0; ind < s.length(); ind++){
            freq[s[ind]] += 1;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it : freq){
            pq.push({it.second, it.first});
        }

        string ans = "";
        while(!pq.empty()){
            int count = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            for(int i = 1; i <= count; i++){
                ans += ch;
            }
        }

        return ans;
    }
};