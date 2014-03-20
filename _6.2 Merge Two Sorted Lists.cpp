#include <iostream>
using namespace std;

struct LinkList
{
    int value;
    struct LinkList *next;

    LinkList(int value_, struct LinkList *next_){
        value = value_;
        next = next_;
    }
};

struct LinkList* merge(struct LinkList *a, struct LinkList *b)
{

}

int print(struct LinkList *head)
{
    struct LinkList *ptr = head;
    while(ptr){
        cout <<ptr->value<<" ";
        ptr = ptr->next;
    }
    cout <<endl;
}

int main()
{
    LinkList s14(7, NULL);
    LinkList s13(5, &s14);
    LinkList s12(3, &s13);
    LinkList s11(1, &s12);
    print(&s11);

    LinkList s22(4, NULL);
    LinkList s21(2, &s22);
    print(&s21);

    struct LinkList *head = merge(&s11, &s21);
    print(head);


}
