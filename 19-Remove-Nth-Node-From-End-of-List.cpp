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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* toDelete = NULL;
        stack<ListNode*> holder1;
        while (temp != NULL) {
            holder1.push(temp);
            temp = temp->next;
        }
        for (int i = 0; i < n; i++) {
            holder1.pop();
        }
        if (holder1.size() > 0) {
            temp = holder1.top();
        } else {
            /*Means the head will be deleted*/
            temp = head->next;
            head->next = NULL;
            delete head;
            return temp;
        }
        toDelete = temp->next;
        temp->next = toDelete->next;
        toDelete->next = NULL;
        delete toDelete;
        return head;
    }
};