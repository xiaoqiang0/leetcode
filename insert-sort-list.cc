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
        ListNode *insertionSortList(ListNode *head) {
            int n = 0;
            ListNode *p = head;
            ListNode *q;
            ListNode *t = head;;
            
            if (p == NULL) return head;
            q = p->next;
            if (q == NULL) return head;
            
            while(q) {
                t ->next = q->next;
                ListNode *s = NULL;
                p = head;
                while( p != t->next && p->val < q->val){
                    s = p;
                    p = p->next;
                }

                if (s == NULL){
                    q->next = head;
                    head = q;
                } else if (p == t->next) {
                    q->next = t->next;
                    t->next = q;
                    t = q;
                } else {
                    q->next = s->next;
                    s->next = q;
                }
                
                q = t->next;

            }

            return head;
        }
};

int main()
{
    ListNode * head = new ListNode(2);
    head->next= new ListNode(1);
/*
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
*/

    Solution S;
    ListNode *p;
    p = S.insertionSortList(head);
    while (p){
        cout <<p->val<< " ";
        p = p->next;
    }
    cout <<endl;
    return 0;
}
