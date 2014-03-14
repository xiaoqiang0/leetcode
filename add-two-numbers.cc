#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *p, *q, *t;
            ListNode *head = NULL;
            p = l1;

            if (l1 == NULL) return l2;
            if (l2 == NULL) return l1;
            
            int flag = 0;
            t = NULL;
            p = l1; q = l2;
            while (p && q) {
                //ListNode *op1 = S1.top();
                //ListNode *op2 = S2.top();
                int v = p->val + q->val;

                if (flag == 1)
                    v++;

                if (v >= 10) {
                    flag = 1;
                    v = v % 10;
                } else
                    flag = 0;

                ListNode *node = new ListNode(v);
                
                if (head == NULL){
                    head = node;
                    t = node;
                }else{
                    t->next = node;
                    t = node;
                }

                p = p->next;
                q = q->next;
            }

            while (p){
                int v = p->val;

                if (flag == 1)
                    v++;

                if (v >= 10) {
                    flag = 1;
                    v = v % 10;
                } else
                    flag = 0;

                ListNode *node = new ListNode(v);
                if (head == NULL){
                    head = node;
                    t = node;
            }else{
                    t->next = node;
                    t = node;
                }
                p = p->next;
            }


            while (q){
                int v = q->val;

                if (flag == 1)
                    v++;

                if (v >= 10) {
                    flag = 1;
                    v = v % 10;
                } else
                    flag = 0;

                ListNode *node = new ListNode(v);
                if (head == NULL) {
                    head = node;
                    t = node;
                }else{
                    t->next = node;
                    t = node;
                }
                q=q->next;
            }

            if (flag == 1) {
                ListNode *node = new ListNode(1);
                if (head == NULL){
                    head = node;
                    t = node;
                }else{
                    t->next = node;
                    t = node;
                }
            }
            
            //Link all nodes to on list
            
            return head;
        }
};
int main()
{
    struct ListNode * head1 = new ListNode(9);
    head1->next= new ListNode(1);
    head1->next->next = new ListNode(6);
//    head1->next->next->next = new ListNode(4);
//    head1->next->next->next->next = new ListNode(5);

struct ListNode * head2 = new ListNode(0);
/*    head2->next= new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
*/
    Solution S;
    ListNode *head = S.addTwoNumbers(head1, head2);
    while (head){
        cout <<head->val <<" " <<endl;
        head= head->next;
    }
    cout <<endl;

    return 0;
}
