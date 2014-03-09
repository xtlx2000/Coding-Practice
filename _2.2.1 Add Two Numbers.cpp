#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    struct ListNode *next;
};

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

struct ListNode *addTwoNumbers(struct ListNode *num1, struct ListNode *num2)
{
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    struct ListNode *ptr1 = num1;
    struct ListNode *ptr2 = num2;

    int pow = 0;
    while(num1 && num2){
        int num = num1->value + num2->value;
        pow = num / 10;
        num %= 10;
    }
}

int main()
{
    struct ListNode LN1;
    struct ListNode LN2;
    struct ListNode LN3;
    struct ListNode LN4;
    struct ListNode LN5;
    struct ListNode LN6;

    LN1.value = 2;
    LN2.value = 4;
    LN3.value = 3;
    LN4.value = 5;
    LN5.value = 6;
    LN6.value = 4;

    LN1.next = &LN2;
    LN2.next = &LN3;
    LN3.next = NULL;

    LN4.next = &LN5;
    LN5.next = &LN6;
    LN6.next = NULL;


}
