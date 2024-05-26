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

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* half = head;
        ListNode* temp = head;
        int n = 0;
        while(temp->next && temp->next->next){
            temp = temp->next->next;
            half = half->next;
        }

        if(temp->next){
            half=half->next;
        }
        
        half = reverseList(half);
        ListNode* temp1 = head->next;
        ListNode* temp2 = half->next;
        while (half&&head) {
            temp1 = head->next;
            temp2 = half->next;
            head->next = half;
            half->next = temp1;
            head = temp1;
            half = temp2;
        }
        if(head && head->next){
            head->next->next=NULL;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }

};