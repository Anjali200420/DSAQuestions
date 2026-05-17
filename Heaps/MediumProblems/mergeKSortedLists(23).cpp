/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 1. Putting all elements in priority queue
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(auto it : lists){
            if(it) pq.push({it -> val, it});
        }

        //Handling Edge case
        if(pq.empty()) return {};

        // 2. Creating ListNode for returning
        ListNode* node = pq.top().second;
        pq.pop();

        if(node -> next) pq.push({node -> next -> val, node -> next});
        ListNode* ans = node;
        ListNode* temp = ans;

        while(!pq.empty()){
            ListNode* node = pq.top().second;
            pq.pop();

            if(node -> next) pq.push({node -> next -> val, node -> next});
            temp -> next = node;
            temp = temp -> next;
        }

        return ans;
    }
};