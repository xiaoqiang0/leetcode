#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <limits>
#include <map>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:

        void quick_sort(ListNode **begin, ListNode **end)
        {
            ListNode *head = NULL, *p, *q, *s, *t = *begin;
            int k = t->val;

            if (*begin == *end) return;

            t = *begin;
            q = t;
            s = t;
            t = t->next;

            while (1){
                if (t->val < k) {
                    s->next = t->next;

                    if (head == NULL){
                        head = t;
                        p = t;
                    } else {
                        p->next = t;
                        p = p->next;
                    }
                } else {
                    s = t;
                }
                if (t == *end)
                    break;
                t = s->next;
            }

            if (head){
                p->next = *begin;
                quick_sort(&head, &p);
                *begin = head;
                p->next = q;
            }

            if (q != s){
                quick_sort(&(q->next), &s);
            }

            *end = s;
        }




        ListNode *sortList(ListNode *head)
        {
            ListNode *p = head;
            if (head == NULL)
                return NULL;

            while (p->next != NULL){
                p = p->next;
            }
            
            quick_sort(&head, &p);

            return head;
        }
};
int main()
{
    Solution S;
    struct ListNode * head = new ListNode(3);
    head->next= new ListNode(5);
    head->next->next = new ListNode(9);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(1);
/*
*/
    head = S.sortList(head);

    while (head){
        cout <<head->val <<" " <<endl;
        head= head->next;
    }
    cout <<endl;

    return 0;
}
