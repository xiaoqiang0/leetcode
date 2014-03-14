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
            stack<ListNode *> S1, S2, S;
            ListNode *p, *q;

            p = l1;
            while (p) {
                S1.push(p);
                p = p->next;
            }
            p = l2;
            while (p) {
                S2.push(p);
                p = p->next;
            }
            
            if (S1.empty()) return l2;
            if (S2.empty()) return l1;
            
            int flag = 0;
            while (!S1.empty() && !S2.empty()) {
                //ListNode *op1 = S1.top();
                //ListNode *op2 = S2.top();
                int v = S1.top()->val + S2.top()->val;

                if (flag == 1)
                    v++;

                if (v >= 10) {
                    flag = 1;
                    v = v % 10;
                } else
                    flag = 0;

                ListNode *node = new ListNode(v);

                S.push(node);

                S1.pop(); S2.pop();
            }

            if (!S1.empty()){
                int v = S1.top()->val;

                if (flag == 1)
                    v++;

                if (v >= 10) {
                    flag = 1;
                    v = v % 10;
                } else
                    flag = 0;

                ListNode *node = new ListNode(v);

                S.push(node);

                S1.pop();
            }


            if (!S2.empty()){
                int v = S2.top()->val;

                if (flag == 1)
                    v++;

                if (v >= 10) {
                    flag = 1;
                    v = v % 10;
                } else
                    flag = 0;

                ListNode *node = new ListNode(v);

                S.push(node);

                S2.pop();
            }

            if (flag == 1) {
                S.push(new ListNode(1));
            }
            
            //Link all nodes to on list
            
            ListNode *head = NULL;
            p = NULL;
            while (!S.empty()){
                q = S.top();
                if (p == NULL){
                    p = q;
                } else {
                    q->next = p;
                    p = q;
                }

                S.pop();
            }
            return p;
        }
};
int main()
{
    struct ListNode * head1 = new ListNode(1);
    head1->next= new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

struct ListNode * head2 = new ListNode(1);
    head2->next= new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    Solution S;
    ListNode *head = S.addTwoNumbers(head1, head2);
    while (head){
        cout <<head->val <<" " <<endl;
        head= head->next;
    }
    cout <<endl;

    return 0;
}
