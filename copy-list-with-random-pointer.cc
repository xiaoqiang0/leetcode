#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, int> add2idx;
        if (head == NULL) return NULL;
        RandomListNode *p = head;
        RandomListNode *new_head = NULL, *t;
        int n = 0;
        while(p){
            add2idx[p] = n++;
            p=p->next;
        }

        vector<int> idx2rand(n, -1);
        vector<RandomListNode *> idx2add;
        p = head;
        int i = 0;
        while (p){
            if (p->random)
                idx2rand[i] = add2idx[p->random];
            p = p->next;
            i++;
        }

        p = head;
        i = 0;
        while (p) {
            RandomListNode *s = new RandomListNode(p->label);
            idx2add.push_back(s);
            if (new_head == NULL){
                new_head = s;
                t = s;
            } else {
                t->next = s;
                t = s;
            }

            p = p->next;
        }

        p = new_head;
        i = 0;
        while(p){
            if (idx2rand[i] != -1)
                p->random = idx2add[idx2rand[i]];
            i++;
            p=p->next;
        }
    
        return new_head;
    }
};

int main()
{
    RandomListNode *head = new RandomListNode(1);
//    head->next = new RandomListNode(2);
 //   head->next->next = new RandomListNode(3);
/*
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head;
    */
    Solution S;

    head = S.copyRandomList(head);

    return 0;
}
