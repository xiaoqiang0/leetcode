#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode *pre_p;
        TreeNode *pre;
        void left_node(TreeNode *root, TreeNode *parent, TreeNode **r, TreeNode **rp)
        {
            if (root){
                left_node(root->left, root, r, rp);

                if (*r != NULL) return;
                
                if (pre != NULL && pre->val > root->val){
                    *r = pre;
                    *rp = pre_p;
                    return;
                }
                pre = root;
                pre_p = parent;

                if (*r != NULL) return;

                left_node(root->right, root, r, rp);
            }
        }
        void right_node(TreeNode *root, TreeNode *parent, TreeNode **r, TreeNode **rp)
        {
            if (root){
                right_node(root->right, root, r, rp);

                if (*r != NULL) return;
                
                if (pre != NULL && pre->val < root->val){
                    *r = pre;
                    *rp = pre_p;
                    return;
                }
                pre = root;
                pre_p = parent;

                if (*r != NULL) return;
                right_node(root->left, root, r, rp);

            }

        }
        void recoverTree(TreeNode *root) {
            pre = NULL;
            pre_p = NULL;
            TreeNode *l = NULL, *lp = NULL;
            TreeNode *r = NULL, *rp = NULL;

            left_node(root, NULL, &l, &lp);
            pre = NULL;
            pre_p = NULL;
            right_node(root, NULL, &r, &rp);
            pre = NULL;

            /* hack
               int t = l->val;
               l->val = r->val;
               r->val = t;
               return;
             */

            if (lp == r) {
                if (rp == NULL){
                    TreeNode *tl, *tr;
                    tl = l->left;
                    tr = l->right;

                    l->left = r;
                    l->right = r->right;
                    r->left = tl;
                    r->right = tr;
                } else {
                    TreeNode *tl, *tr;
                    tl = l->left;
                    tr = l->right;
                    l->right = r->right;
                    l->left = r;
                    
                    r->left = tl;
                    r->right = tr;
                    if (rp->left == r)
                        rp->left = l;
                    else
                        rp->right = l;
                
                }
            } else if (l == rp) {
                if (lp == NULL){
                    TreeNode *tl, *tr;
                    tl = r->left;
                    tr = r->right;

                    r->left = l->left;
                    r->right = l;
                    l->left = tl;
                    l->right = tr;
                    root = r;
                } else {
                    TreeNode *tl, *tr;
                    tl = r->left;
                    tr = r->right;
                    r->right = l;
                    r->left = l->left;
                    
                    l->left = tl;
                    l->right = tr;
                    if (lp->left == l)
                        lp->left = r;
                    else
                        lp->right = r;

                } 
            } else {
                if (lp && rp){
                    if (lp->left == l)
                        lp->left = r;
                    else
                        lp->right = r;

                    if (rp->left = r)
                        rp->left = l;
                    else 
                        rp->right = l;

                    TreeNode *tl, *tr;

                    tl = l->left;
                    tr = l->right;
                    l->left = r->left;
                    l->right = r->right;
                    r->left = tl;
                    r->right = tr;

                } else if (lp == NULL) {
                    //l is root node
                    //r-->l

                    TreeNode *tl, *tr;

                    tl = l->left;
                    tr = l->right;

                    if (rp->left = r)
                        rp->left = l;
                    else
                        rp->right =l;
                    l->left = r->left;
                    l->right = r->right;
                    r->left = tl;
                    r->right = tr;

                } else if (rp == NULL) {
                    TreeNode *tl, *tr;

                    tl = r->left;
                    tr = r->right;

                    if (lp->left = l)
                        lp->left = r;
                    else
                        lp->right =r;
                    r->left = l->left;
                    r->right = l->right;
                    l->left = tl;
                    l->right = tr;
                }
            }
        }
};


int main()
{
    TreeNode *root = new TreeNode (3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode (4);


/*
    TreeNode *root = new TreeNode (6);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode (3);


    root->right = new TreeNode (4);
    root->right->left = new TreeNode (5);
    root->right->right = new TreeNode (7);
*/
    Solution S;
    S.recoverTree(root);
    return 0;
}
