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
        void reorderList(ListNode *head) {
            int n = 0;
            ListNode *p = head;
            while (p) {
                n ++;
                p = p->next;
            }

            if (n == 0|| n == 1)
                return ;

            ListNode *q;
            p = head;
            q  = p->next;

            int i = n / 2 - 1;
            
            while (i) {
                ListNode *t;
                p->next = q->next;
                t = q->next;
                q->next = head;
                head = q;
                q = t;
                i--;
            }

            if (n % 2 == 1) q = q->next;
/*
            p = head;
            while (p) {
                cout <<p->val << "";
                p=p->next;
            }
            cout <<endl;
*/
            p = head;
            
            while (q){
                ListNode *t;
                t = p->next;
                head = t;
                p->next = q->next;
                q->next = p;
                q = p->next;
                p = t;
            }

/*
            p = head;
            while (p) {
                cout <<p->val << "";
                p=p->next;
            }
            cout <<endl;
*/
            p = head;
            q = p->next;
            while (q) {
                ListNode *t;
                p->next = q->next;
                t = q->next;
                q->next = head;
                head = q;
                q = t;
            }

/*
            p = head;
            while (p) {
                cout <<p->val << "";
                p=p->next;
            }
            cout <<endl;
*/

        }
};

int main()
{
    ListNode * head = new ListNode(1);
    head->next= new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
/*
*/

    Solution S;
    ListNode *p;
    S.reorderList(head);
    p = head;
    while (p){
        cout <<p->val<< " ";
        p = p->next;
    }
    cout <<endl;
    return 0;
}
