#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *old);

int main()
{
    struct ListNode LN1;
    struct ListNode LN2;
    struct ListNode LN3;


    LN1.value = 2;
    LN2.value = 4;
    LN3.value = 3;


    LN1.next = &LN2;
    LN2.next = &LN3;
    LN3.next = NULL;


    struct ListNode *ptr = &LN1;
    while(ptr){
        cout <<ptr->value<<" ";
        ptr = ptr->next;
    }
    cout <<endl;

    ptr = &LN1;
    ptr = reverseList(ptr);
    while(ptr){
        cout <<ptr->value<<" ";
        ptr = ptr->next;
    }
    cout <<endl;
}

struct ListNode *reverseList(struct ListNode *old)
{
    struct ListNode *i, *j, *k;
    i = old;
    j = old->next;
    i->next = NULL;

    while(j){
        k = j->next;
        j->next = i;
        i = j;
        j = k;
    }

    return i;
}
