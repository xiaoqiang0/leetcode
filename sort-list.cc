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

        void quick_sort(ListNode **begin, ListNode **end, int n)
        {
            ListNode *head = NULL, *p, *q, *s, *t = *begin;
            int k = t->val;

            if (*begin == *end) return;
            if (n == 2){
                int x;
                x = 1;
            }

            /*
               if (n < 100)
               insert_sort
             */
            t = *begin;
            /*Find the mid of 1-10*/
            int found = 0, c = n - 1;
            int min = t->val;
            int max = t->val;
            p = t; // point the first node
            q = p->next;

            while (q && c){
                int v = q->val; 
                if (v > min && v < max){
                    found = 1;
                    break;
                }
                if (v > max) max = v;
                if (v < min) min = v;
                p = q;
                q = q->next;
                c--;
            }

            if (found == 1){
                //swap q and *begin
                p->next = q->next;
                q->next = (*begin)->next;
                (*begin)->next = p->next;
                p->next = (*begin);

                if (q == *end)
                    *end = *begin;

                *begin = q;

            }
            t = *begin;
            head = p = NULL;
            q = t; //point to middle
            s = t;
            t = t->next;

            k = q->val;

            int left_size = 0;
            while (1){

                if (t->val < k) {
                    s->next = t->next;
                    left_size ++;
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
                quick_sort(&head, &p, left_size);
                *begin = head;
                p->next = q;
            }

            if (q != s){
                quick_sort(&(q->next), &s, n - left_size - 1);
            }
            // Set the end of sorted list
            *end = s;
        }




        ListNode *sortList(ListNode *head)
        {
            ListNode *p = head;
            int n = 0;
            if (head == NULL)
                return NULL;

            while (p->next != NULL){
                p = p->next;
                n++;
            }
            n++;
            
            quick_sort(&head, &p, n);

            return head;
        }
};
int main()
{
    //int A[] = {4, 19, 14, 5, -3, 1, 8};
    int A[] = {4,19,14,5,-3,1,8,5,11,15};
    //int A[] = {9,-3, 1, 8};
    Solution S;

    struct ListNode * head = NULL, *p;
    
    for (int i = 0; i < sizeof(A)/sizeof(int); i++) {
        ListNode *t = new ListNode(A[i]);
        if (head == NULL){
            head = t;
            p = t;
        } else {

            p ->next = t;
            p = t;
        }
    }

    head = S.sortList(head);

    while (head){
        cout <<head->val <<" " <<endl;
        head= head->next;
    }
    cout <<endl;

    return 0;
}
