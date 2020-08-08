/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyNode(-1);
        dummyNode.next = head;

        ListNode *prev = &dummyNode;
        ListNode *start = dummyNode.next;

        bool isMatch = true;
        while (start && isMatch)
        {
            ListNode *end = start;
            for (size_t i = 0; i < k-1; ++i)
            {
                if (end->next)
                {
                    end = end->next;
                }
                else
                {
                    isMatch = false;
                    break;
                }
            }
            if (!isMatch)
            {
                break;
            }
            reverse(prev, start, end);

            prev = start;
            start = start->next;
        }
        return dummyNode.next;
    }
    void reverse(ListNode *prev, ListNode *start, ListNode *end)
    {
        ListNode *tail = end->next;

        ListNode *first = start;
        ListNode *second = start->next;
        
        while (first != end)
        {
            ListNode *third = second->next;
            
            second->next = first;

            first = second;
            second = third;
        }

        prev->next = end;
        start->next = tail;
    }
};