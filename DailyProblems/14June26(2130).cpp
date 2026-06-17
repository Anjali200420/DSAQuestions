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
private:
    // Method to reverse the Nodes
    ListNode* reverseNode(ListNode* node){
        ListNode* prev = NULL;

        while(node){
            ListNode* next = node -> next;

            node -> next = prev;

            prev = node;
            node = next;
        }

        return prev;
    }
public:
    int pairSum(ListNode* head) {
        // Find the middle node (Hare & Tortoise algorithm)
        ListNode* slow = head;
        ListNode* fast = head;

        stack<int> st;
        while(fast && fast -> next){
            st.push(slow -> val);

            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // Reversing the half node
        //slow -> next = reverseNode(slow -> next);
        
        // Calculating the maximum twin sum
        int ans = 0;
        while(slow){
            int temp = st.top();
            st.pop();


            ans = max(ans, (slow -> val + temp));
            slow = slow -> next;
        }

        return ans;
    }
};