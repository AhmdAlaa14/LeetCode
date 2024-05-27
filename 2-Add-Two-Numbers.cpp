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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        bool moreThanTen = false;
        sum = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* result = new ListNode(sum % 10, NULL);
        ListNode* end = result;

        if (sum >= 10) {
            moreThanTen = true;
        }

        while (l1 && l2) {
            sum = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            if (moreThanTen) {
                sum++;
            }
            ListNode* temp = new ListNode(sum % 10, NULL);
            end->next = temp;
            end = end->next;
            moreThanTen = (sum >= 10);
        }
        while (l1) {
            sum = l1->val;
            if (moreThanTen) {
                sum++;
            }
            ListNode* temp = new ListNode(sum % 10, NULL);
            l1 = l1->next;
            end->next = temp;
            end = end->next;
            moreThanTen = (sum >= 10);
        }
        while (l2) {
            sum = l2->val;
            if (moreThanTen) {
                sum++;
            }
            ListNode* temp = new ListNode(sum % 10, NULL);
            l2 = l2->next;
            end->next = temp;
            end = end->next;
            moreThanTen = (sum >= 10);
        }
        if (moreThanTen) {
            ListNode* temp = new ListNode(1, NULL);
            end->next = temp;
        }
        return result;
    }
};