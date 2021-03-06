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
        ListNode *detectCycle(ListNode *head) {
            struct ListNode *p, *q, *t;

            p = head;
            if (p == NULL) return false;

            q = p->next;
            if (q == NULL) return false;

            do {
                if (p == q)
                    break;
                if (q->next == NULL || q->next->next == NULL)
                    return NULL;

                q = q->next->next;
                p = p->next;

            } while (1);

            t = q;
            p = head;
            q = t->next;
            while (p != t && q != t){
                p = p->next;
                q = q->next;
            }
            if (p != t){
                q = head;
                while (p != t){
                    p = p->next;
                    q = q->next;
                }
                p = t->next;
            } else if (q != t) {
                p = t->next;
                while( q != t){
                    q = q->next;
                    p = p->next;
                }
                q = head;
            } else if (q == t && p == t){
                p = head;
                q = t->next;
            }


            while (p != q){
                p = p->next;
                q = q->next;
            }

            return p;
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

        ListNode *deleteDuplicates2(ListNode *head) {
            ListNode *p;
            ListNode *q;

            if (head == NULL) return NULL;

            p = NULL;

            q = head;
            head = NULL;
            while (q != 0) {
                ListNode *t = q;
                if (q->next && q->next->val == q->val){
                    while (q->next && q->next->val == q->val)
                        q=q->next;
                    q = q->next;
                    continue;
                }
                if (p == NULL){
                    head = q;
                    p = q;
                    q = q->next;
                    p->next = NULL;
                }else {
                    p->next = q;
                    p = q;
                    q = q->next;
                    p->next = NULL;
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();

        if (n == 0) return NULL;
        if (n == 1) return lists[0];

        ListNode *head, *p;

        head = lists[0];

        for (int i = 1; i < n; i++){
            p = lists[i];

            head = mergeTwoLists(head, p);
        }
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

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int c = 0;

        ListNode *p = head;

        if (head == NULL) return head;
        while (p){
            c++;
            p = p->next;
        }
        
        if (n > c || n < 0) return head;

        n = c - n;
        
        if (n == 0)
            return head->next;
        p = head;
        n--;
        while (n){
            p = p->next;
            n--;
        }

        p->next = p->next->next;
        
        return head;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *p = head;
        int c = m;
        ListNode *q, *t;

        c -= 2;
        while (c > 0){
            p = p->next;
            c--;
        }

        n = n - m;
        if (m > 1) {
            if (n >= 0){
                q = p->next->next;
                t = p->next;
            }

            while (t && n){
                t->next = q->next;
                q->next = p->next;
                p->next = q;
                q = t->next;
                n--;
            }

        } else {
            t = head;
            q = t->next;
            while (n) {
                t->next = q->next;
                q->next = head;
                head = q;
                q = t->next;
                n--;
            
            }
        }

        return head;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *p, *q, *s, *t, *x = NULL;
        ListNode *new_head = NULL;
        t = head;
        p = head;
        q = head;

        while (t){
            int c = k-1;

            while (t && c){
                t=t->next;
                c--;
            }

            if (t == NULL ||c > 0)
                break;

            //reverse
            q = t;
            s = p;
            if (new_head == NULL) new_head = q;
            
            while(s != q) {
                if (x == NULL) {
                    s=s->next;
                } else {
                    x->next = p->next;
                    s = x->next;
                }
                p->next = q->next;
                q->next = p;
                p = s;
            }

            //find end;
            c = k-1;
            x = q;
            while (c){
                x=x->next;
                c--;
            }

            t = x->next;
            p = t;
        }
        
        if (new_head == NULL)
            return head;
        else
            return new_head;
    }

    ListNode *rotateRight(ListNode *head, int k) {
        int n = 0;
        ListNode *p = head;
        ListNode *q = head;
        if (head == NULL) return head;

        while (p){
            n++;
            q = p;
            p=p->next;
        }
        k = k % n;

        k = n - k;
        p = head;
        while (k){
            q->next = p;
            p = p->next;
            q = q->next;
            q->next = NULL;
            k--;
        }

        head = p;

        return head;
    }
};

int main()
{
    Solution S;
    struct ListNode * head = new ListNode(1);
    head->next= new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
/*
    head->next->next->next->next->next = head->next;

    //head->next->next->next->next->next = head;

    ListNode *p = S.detectCycle(head);

    cout <<p->val <<endl;

    if (S.hasCycle(head))
        cout << "has cycle" <<endl;
    else
        cout << "no cycle" <<endl;
    S.deleteDuplicates(head);
    head = S.swapPairs(head); 
    while (head) {
        cout <<head->val <<" ";
        head=head->next;
    }
    head = S.reverseBetween(head, 2, 5);
    head = S.rotateRight(head, 2);
*/
    head = S.reverseKGroup(head, 1);
    while (head){
        cout <<head->val <<" " <<endl;
        head= head->next;
    }
    cout <<endl;

    return 0;
}
