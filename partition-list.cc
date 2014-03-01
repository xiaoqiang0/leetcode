#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/**
Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            int n = 0;
            ListNode *p = head;
            ListNode *q;
            ListNode *t;

            if (p == NULL) return head;
            q = p->next;
            if (q == NULL) return head;
            t = head;
            
            p = NULL;

            /*
             p

             s t;
             
             */
            ListNode *s = NULL;
            while (t && t->val >= x) {
                s = t;
                t = t->next;
            }
            
            if (t == NULL) return head;

            
            if (s == NULL) {
                p = t;
                s = t;
                t = t->next;
            } else {
                s->next = t->next;
                t->next = head;
                head = t;
                p = t;
                t = s->next;
            }
            while (t) {
                if (t->val < x) {
                        s->next = t->next;
                        t->next = p->next;
                        p->next = t;
                        if (s == p) {
                            s = p->next;
                        }
                        p = p->next;
                        t = s->next;
                } else {
                        s = t;
                        t = t->next;
                }
            }
         
            return head;
        }
};

int main()
{
    ListNode * head = new ListNode(3);
    head->next= new ListNode(1);
    head->next->next = new ListNode(2);
/*
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
*/
    Solution S;
    ListNode *p;
    //p = S.partition(head, 10);
    p = S.partition(head, 3);
    while (p){
        cout <<p->val<< " ";
        p = p->next;
    }
    cout <<endl;
    return 0;
}
