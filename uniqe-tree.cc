#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
    TreeNode * root;
    TreeNode * br; //Bottom right node
    Node(TreeNode * root, TreeNode * br) : root(root), br(br) {}
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
        int numTrees(int n) {
            int sum;
            if (n == 1) return 1;
            if (n == 2) return 2;

            sum = 2 * numTrees(n - 1);

            for (int i = 1; i <= n-2; i++) {
                sum += numTrees(i) * numTrees(n - 1 - i);
            }
            return sum;
        }

        TreeNode * copy_Tree(TreeNode *root, TreeNode *old_br, TreeNode **br, int inc = 0){
            if (root == NULL) return NULL;

            TreeNode *res = new TreeNode (root->val + inc);

            if (root == old_br)
                *br = res;
            res->left = copy_Tree(root->left, old_br, br, inc);
            res->right = copy_Tree(root->right, old_br, br, inc);

            return res;
        }
        vector<Node *> _generateTrees(int n) {
            vector<Node *> res;

            if (n == 0)
                return res;

            if (n == 1) {
                TreeNode *root = new TreeNode(1);
                res.push_back(new Node(root, root));
                return res;
            }
            if (n == 2) {
                TreeNode *root = new TreeNode(1);
                root->right = new TreeNode(2);
                res.push_back(new Node(root, root->right));
                root = new TreeNode(2);
                root->left = new TreeNode(1);
                res.push_back(new Node(root, root));
                return res;
            }

            vector<Node *> t = _generateTrees(n-1);

            for (int i = 0; i < t.size(); i++){
                TreeNode *br;
                TreeNode *root = new TreeNode(n);

                root->left = t[i]->root;
                res.push_back(new Node(root, root));

                root = copy_Tree(t[i]->root, t[i]->br, &br);

                br->right = new TreeNode(n);

                res.push_back(new Node(root, br->right));
            }

            for (int i = 1; i <= n-2; i++) {
                TreeNode * root;
                TreeNode * root1;
                TreeNode * root2;
                TreeNode *br1;
                TreeNode *br2;

                vector<Node *>M = _generateTrees(i);
                vector<Node *>N = _generateTrees(n - 1 - i);

                for (int j = 0; j < M.size(); j ++)
                    for(int k = 0; k < N.size(); k ++){
                        //m[i] * n[k]

                        root = new TreeNode(n);
                        root1 = copy_Tree(M[j]->root, M[j]->br, &br1);
                        root2 = copy_Tree(N[k]->root, N[k]->br, &br2, i);

                        br1->right = new TreeNode(n);
                        br1->right->left = root2;

                        res.push_back(new Node(root1, br1->right));
                    }

            }

            return res;
        } 

        vector<TreeNode *> generateTrees(int n) {
            vector<TreeNode *> res;

            if (n == 0){
                res.push_back(NULL);
                return res;
            }
            vector<Node *> res1 = _generateTrees(n);

            for (int i = 0; i < res1.size(); i++)
                res.push_back(res1[i]->root);
            return res;
        }

};


int main()
{
    Solution S;
    cout << "numTrees(3):" <<S.numTrees(3)<<endl;
    cout << "numTrees(4):" <<S.numTrees(4)<<endl;
    cout << "numTrees(5):" <<S.numTrees(5)<<endl;
    vector<TreeNode *> res = S.generateTrees(3);

    cout <<"tree vector size:" << res.size() <<endl;
    
    for (int i = 0; i < res.size(); i++) {
        S.preorder(res[i]);
        cout <<endl;
        S.inorder(res[i]);
        cout <<endl;
        cout <<endl;
    }
        
    return 0;
}
