#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        void preorder(TreeNode *root)
        {
            if (root == NULL) return;
            cout <<root->val << " ";
            preorder(root->left);
            preorder(root->right);
        } 
        void inorder(TreeNode *root)
        {
            if (root == NULL) return;
            inorder(root->left);
            cout <<root->val << " ";
            inorder(root->right);
        }

        void insertBST(TreeNode  **root, int v, bool &taller, map<TreeNode *, int> &t2bf) {
            TreeNode *p = *root;
            if (p == NULL){
                p = new TreeNode(v);
                *root = p;
                taller = 1;
                t2bf[p] = 0;
            } else {
                insertBST(&(p->right), v, taller, t2bf);
                if (taller == false)
                    return;

                TreeNode *rc = p->right;
                switch(t2bf[p]){
                    case  1:
                        t2bf[p] = 0;
                        taller = false;
                    break;
                        case  0:
                        t2bf[p] = -1;
                        taller = true;
                    break;
                        case -1:
                        t2bf[p]  = 0;
                        t2bf[rc] = 0;

                        *root = rc;
                        p->right = rc->left;
                        (*root)->left = p;
                        taller = false;
                }

            }


        }

        TreeNode *sortedListToBST(ListNode *head) {
            TreeNode *root = NULL;
            ListNode *p = head;
            bool t;

            if (head == NULL) return root;

            map<TreeNode*, int> t2bf;
            while(p) {
                insertBST(&root, p->val, t, t2bf);
                p = p->next;
            }

            return root;
        }
};
int main()
{
    struct ListNode * head = new ListNode(1);
    head->next= new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution S;
    TreeNode *root = S.sortedListToBST(head);

    S.preorder(root);
    cout <<endl;
    S.inorder(root);
    cout <<endl;

    return 0;
}
