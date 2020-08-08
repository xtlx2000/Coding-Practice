/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool findNextGroup(ListNode *prev, ListNode* start, ListNode **end, ListNode **tail, int k)
    {
        if (start == NULL)
        {
            return false;
        }
        
        *end = start;
        for (int i = 0; i < k-1; ++i)
        {
            if ((*end)->next)
            {
                *end = (*end)->next;
            }
            else
            {
                return false;
            }
        }
        if (*end)
        {
            *tail = (*end)->next;
        }
        return true;
    }

    void reverse (ListNode *prev, ListNode *start, ListNode *end, ListNode *tail)
    {
        ListNode *first = start;
        ListNode *second = first->next;

        while (first &&　second && first != end)
        {
            ListNode *thrid = second->next;

            second->next = first;
            first = second;
            second = thrid;
        }

        prev->next = end;
        start->next = tail;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *start = dummy.next;
        ListNode *end = start;
        ListNode *tail = start;

        while (findNextGroup(prev, start, &end, &tail, k))
        {
            reverse(prev, start, end, tail);

            prev = start;
            start = prev->next;
        } 

        return dummy.next;
    }
};