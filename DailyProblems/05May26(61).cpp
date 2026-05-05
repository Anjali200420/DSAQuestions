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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        
        ListNode* temp = head;

        int totalNodes = 1;
        while(temp -> next){
            totalNodes++;
            temp = temp -> next;
        }

        temp -> next = head;
        
        k = (k%totalNodes);
        int numOfRotations = totalNodes - k;

        temp = head;
        while(--numOfRotations){
            temp = temp -> next;
        }

        ListNode* ans = temp -> next;
        temp -> next = NULL;

        return ans;
    }
};