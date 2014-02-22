#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            struct ListNode *p, *q;

            p = head;
            if (p == NULL) return false;

            q = p->next;
            if (q == NULL) return false;

            do {
                if (p == q) return true;

                if (q->next == NULL || q->next->next == NULL) return false;

                q = q->next->next;
                p = p->next;

            } while (1);
        }

        ListNode *deleteDuplicates(ListNode *head) {
            ListNode *p;
            ListNode *q;

            if (head == NULL) return NULL;

            p = head;
            
            q = p->next;

            while (q != 0) {
                if (p->val != q->val) {
                    p = q;
                    q = q->next;
                } else {
                    p->next = q->next;
                    delete q;
                    q = p->next;
                }
            }

            return head;
        }


    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *t = head;
        
        if (l1 == NULL && l2 == NULL) return NULL;

        if (!(p && q)) return q ? q : p;

        while (p && q) {
            if (p->val > q->val) {
                if (head == NULL)
                    head = t = q;
                else 
                    t->next = q;
                t = q;
                q = q->next;
            } else {
                if (head == NULL)
                    head = t = p;
                else 
                    t->next = p;
                t = p;
                p = p->next;
            }
        }
        if (p != NULL)
            t->next = p;
        if (q != NULL)
            t->next = q;

        return head;
    }

    ListNode *swapPairs(ListNode *head) {
        ListNode *p;
        ListNode *q;
        ListNode *t;
        ListNode *H = NULL;

        if (head == NULL || head->next == NULL) return head;

        p = head;
        q = p->next;
        while (p && q) {
            ListNode *r;
            if (H == NULL) {
                H = q;
                t = q;
            } else {
                t->next = q;
            }
            r = q->next;
            q->next = p;
            t = p;
            t->next = NULL;

            p = r;
            if (p == NULL)
                break;
            q = p->next;
        }
        
        if (p) 
            t->next = p;

        return H;

    }
};

int main()
{
    struct ListNode * head = new ListNode(1);
    head->next= new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = head;*/

    Solution S;
/*
    if (S.hasCycle(head))
        cout << "has cycle" <<endl;
    else
        cout << "no cycle" <<endl;
    S.deleteDuplicates(head);
*/
    head = S.swapPairs(head); 
    while (head) {
        cout <<head->val <<" ";
        head=head->next;
    }

    cout <<endl;

    return 0;
}
