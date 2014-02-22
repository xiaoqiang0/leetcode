#include <iostream>
#include <vector>
#include <stack>

using namespace std;


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getDepth(TreeNode *T){
        int ld, rd;
        if (!T) return 0;
        if (T->right && !T->left) return getDepth(T->right) +1
        if (!T->right && T->left) return getDepth(T->left) +1
        ld = getDepth(T->left);
        rd = getDepth(T->right);
        return 1 + (ld < rd ? ld:rd);
    }
    int check(TreeNode * root, bool &isBalanced) {
        int ld, rd;
        if (!T) return 0;
        ld = getDepth(T->left);
        rd = getDepth(T->right);
        if (ld - rd > 1 || rd - ld >1 ) isBalanced = false;
        return 1 + (ld > rd ? ld:rd);
        
    }
    bool isBalanced(TreeNode *root) {

    }
    int maxDepth(TreeNode *root) {
        return getDepth(root);
    }
};

int main()
{
    TreeNode * root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(2);

    Solution s;
    return s.maxDepth(root);
}
