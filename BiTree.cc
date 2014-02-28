#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode *CreateTree(vector<int> &preorder, int pl, int pu, vector<int> &inorder, int il, int iu)
        {
            int len = preorder.size();

            if (preorder.size() != inorder.size()) return NULL;
            if (preorder.size() == 0) return NULL;

            TreeNode *r = new TreeNode(preorder.at(pl));

            // Search the pos of preorder[0]
            vector<int>::iterator elem;
            int pos = il;
            for (vector<int>::iterator it = inorder.begin() + pl; it != inorder.begin() + pu; it++){
                if (*it == preorder.at(0)) {
                    break;
                }
                pos++;
            }

            int l_len = pos - il;
            int r_len = iu - pos;

            if (pos != il)
                r->left = CreateTree(preorder, pl+1, pl + l_len, inorder, il, il + l_len - 1);
            if (pos != iu)
                r->right = CreateTree(preorder, pu - r_len + 1 , pu, inorder, pos +1 , iu);

            return r;

        }

        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            return CreateTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        }

        TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder) {
            TreeNode * root;
            TreeNode *  p;
            int flag = 0;
            int i, j;
            i = j = 0;
            stack<TreeNode *> S;

            if (preorder.size() == 0) return NULL;

            root = new TreeNode(preorder[0]);
            S.push(root);
            p = root;
            i++;
            while (i < preorder.size()){
                if (!S.empty() && S.top()->val == inorder[j]) {
                    flag = 1;
                    p = S.top();
                    S.pop();
                    j++;
                } else {
                    if (flag == 0){
                        p->left = new TreeNode(preorder[i]);
                        i++;
                        S.push(p->left);
                        p = p->left;
                    } else {
                        p->right = new TreeNode(preorder[i]);
                        i++;
                        S.push(p->right);
                        p = p->right;
                        flag = 0;
                    }
                }
            }

            return root;
        }

        TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
            TreeNode * root;
            TreeNode *  p;
            int flag = 0;
            int i, j;
            stack<TreeNode *> S;
            int len = postorder.size();
            if (len == 0) return NULL;

            i = j = len -1;
            root = new TreeNode(postorder[i]);
            S.push(root);
            p = root;
            i--;
            while (i >= 0){
                if (!S.empty() && S.top()->val == inorder[j]) {
                    flag = 1;
                    p = S.top();
                    S.pop();
                    j--;
                } else {
                    if (flag == 0){
                        p->right= new TreeNode(postorder[i]);
                        i--;
                        S.push(p->right);
                        p = p->right;
                    } else {
                        p->left = new TreeNode(postorder[i]);
                        i--;
                        S.push(p->left);
                        p = p->left;
                        flag = 0;
                    }
                }
            }
            return root;
        }

        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode *> S;

            S.push(root);
            res.push_back(root->val);

            while (!S.empty()){
                while (S.top()->left) {
                    TreeNode *t = S.top()->left;
                    res.push_back(t->val);
                    S.push(t);
                }

                TreeNode* top = S.top();S.pop();
                while (top && !top->right && !S.empty()) {
                    top = S.top();
                    S.pop();
                }

                if (top && top->right) {
                    TreeNode *t = top->right;
                    res.push_back(t->val);
                    S.push(t);
                }
            }

            return res;
        }

        vector<int> inorderTraversal_recursive (TreeNode *root) {
            static vector<int> v;
            if (root == NULL) {
                return v;
            }
            inorderTraversal_recursive(root->left);
            v.push_back(root->val);
            inorderTraversal_recursive(root->right);
            return v;
        }
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode *> S;

            if (root == NULL)
                return res;

            S.push(root);

            while (!S.empty()){
                while (S.top()->left) {
                    S.push(S.top()->left);
                }

                TreeNode* top = S.top();S.pop();
                res.push_back(top->val);
                while (top && !top->right && !S.empty()) {
                    top = S.top();
                    res.push_back(top->val);
                    S.pop();
                }

                if (top && top->right) {
                    TreeNode *t = top->right;
                    S.push(t);
                }
            }

            return res;
        }

        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode *> S;

            S.push(root);
            res.insert(res.begin(), root->val);

            while (!S.empty()){
                while (S.top()->right) {
                    TreeNode *t = S.top()->right;
                    res.insert(res.begin(), t->val);
                    S.push(t);
                }

                TreeNode* top = S.top();S.pop();
                while (top && !top->left&& !S.empty()) {
                    top = S.top();
                    S.pop();
                }

                if (top && top->left) {
                    TreeNode *t = top->left;
                    res.insert(res.begin(), t->val);
                    S.push(t);
                }
            }

            return res;
        }

        void preorder_left(TreeNode *root, vector<int> &res) {
            if (root == NULL)
                return;
            res.push_back(root->val);
            inorder_left(root->left, res);
            inorder_left(root->right, res);
        }
        void preorder_right(TreeNode *root, vector<int> &res) {
            if (root == NULL)
                return;
            res.push_back(root->val);
            inorder_right(root->right, res);
            inorder_right(root->left, res);
        }
        void inorder_left(TreeNode *root, vector<int> &res) {
            if (root == NULL)
                return;
            inorder_left(root->left, res);
            res.push_back(root->val);
            inorder_left(root->right, res);
        }
        void inorder_right(TreeNode *root, vector<int> &res) {
            if (root == NULL)
                return;
            inorder_right(root->right, res);
            res.push_back(root->val);
            inorder_right(root->left, res);
        }
        void postorder_left(TreeNode *root, vector<int> &res) {
            if (root == NULL)
                return;
            postorder_left(root->left, res);
            postorder_left(root->right, res);
            res.push_back(root->val);
        }
        void postorder_right(TreeNode *root, vector<int> &res) {
            if (root == NULL)
                return;
            postorder_right(root->right, res);
            postorder_right(root->left, res);
            res.push_back(root->val);
        }
        bool isSymmetric(TreeNode *root) {
            vector<int> res1, res2;

            preorder_left(root, res1);
            inorder_left(root, res1);
            postorder_left(root, res1);

            preorder_right(root, res2);
            inorder_right(root, res2);
            postorder_right(root, res2);

            for (int i = 0;i < res1.size();  i++)
                if (res1[i] != res2[i]) return false;
            return true;
        }

        bool hasPathSum(TreeNode *root, int sum) {
            bool res_left = false, res_right = false;

            if (root == NULL) return false;

            if (root && sum == root->val && !root->left && !root->right) return true;

            if (root->left) res_left = hasPathSum(root->left, sum - root->val);
            if (root->right) res_right =  hasPathSum(root->right, sum - root->val);

            return res_left || res_right;
        }


        bool getPathSum(TreeNode *root, int sum, vector <TreeNode *> &S, vector<vector<int> > &res)
        {
            bool res_left = false, res_right = false;
            if (root == NULL) return false;
            if (root && sum == root->val && !root->left && !root->right){

                vector<int> t;
                for (vector<TreeNode *>::iterator it = S.begin(); it != S.end(); it++){
                    t.push_back((*it)->val);
                }
                t.push_back (root->val);
                res.push_back(t);
                return true;
            }
            if (root->left) {
                S.push_back(root);
                res_left = getPathSum(root->left, sum - root->val, S, res);
                S.pop_back();
            }
            if (root->right) {
                S.push_back(root);
                res_right =  getPathSum(root->right, sum - root->val, S, res);
                S.pop_back();
            }
            return res_left || res_right;


        }
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            vector<vector<int> > res;
            vector<TreeNode *> S;
            getPathSum(root, sum, S, res);
            return res;
        }

        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == NULL && q == NULL) return true;
            if (p && q && p->val != q->val) return false;
            if ((p != NULL && q == NULL) || (q != NULL && p == NULL)) return false;

            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        void connect(TreeLinkNode *root) {
            if (root == NULL) return;
            if (root->left && root->right)
                root->left->next = root->right;
            if (root->next && root->right)
                root->right->next = root->next->left;

            connect(root->left);
            connect(root->right);
        }

        void connect2(TreeLinkNode *root) {
            if (root == NULL) return;
            TreeLinkNode * post;
            post = root->next;
            while (post && !post->left && !post->right && post->next){
                post = post->next;
            }
            if (root->left && root->right) {
                root->left->next = root->right;
                if (post && post->left)
                    root->right->next = post->left;
                else if (post && post->right)
                    root->right->next = post->right;
            } else if(root->left && !root->right) {
                if (post && post->left)
                    root->left->next = post->left;
                else if (post && post->right)
                    root->left->next = post->right;
            } else if(!root->left && root->right) {
                if (post && post->left)
                    root->right->next = post->left;
                else if (post && post->right)
                    root->right->next = post->right;
            }
            connect(root->right);
            connect(root->left);
        }

        TreeNode *createArrayToBST(vector<int> &num, int l, int u)
        {
            if(l > u) return NULL;

            int m = (l + u)/2;

            TreeNode *root = new TreeNode(num[m]);

            root->left = createArrayToBST(num, l, m - 1);
            root->right= createArrayToBST(num, m + 1, u);

            return root;
        }

        TreeNode *sortedArrayToBST(vector<int> &num) {
            int n = num.size();
            int i = n/2;
            if (n == 0) return NULL;

            return createArrayToBST(num, 0, n - 1);
        }

        bool _isValidBST(TreeNode *root, int pre)
        {
            bool ret = true;
            if (root->left)
                ret = _isValidBST(root->left, root->val);
            if (root->val <= pre )
                return false;
            if (root->right)
                ret = (ret || _isValidBST(root->right, root->val));

            return ret;
        }

        bool isValidBST(TreeNode *root) {
            if (root == NULL) return true;

            vector<int> res = inorderTraversal(root);
            if (res.size() == 1) return true;
            for (int i = 0; i < res.size() - 1; i++)
                if (res[i] >= res[i+1])
                    return false;

            return true;
        }

        int maxDepth(TreeNode *root) {
            int ld, rd;
            if (!root) return 0;
            ld = maxDepth(root->left);
            rd = maxDepth(root->right);
            return 1 + (ld > rd ? ld:rd);
        }
        int balanced;
        int check1(TreeNode * T) {
            int ld, rd;
            if (!T) return 0;
            ld = check1(T->left);
            rd = check1(T->right);
            if (ld - rd > 1 || rd - ld >1 ) balanced = false;
            return 1 + (ld > rd ? ld:rd);

        }
        bool isBalanced(TreeNode *root) {
            balanced = true;
            check1(root);
            return balanced;
        }

        int minDepth(TreeNode *root) {
            int ld, rd;
            if (!root) return 0;
            if (root->right && !root->left) return minDepth(root->right) +1;
            if (!root->right && root->left) return minDepth(root->left) +1;
            ld = minDepth(root->left);
            rd = minDepth(root->right);
            return 1 + (ld < rd ? ld:rd);
        }

        /*
           Given a binary tree, find the maximum path sum.
           The path may start and end at any node in the tree.
           For example:
           Given the below binary tree,
           1
           / \
           2   3
           Return 6.
         */
        /*Pending*/
        int get_max(int x, int y, int z)
        {
            if (x>y)
                return x>z?x:z;
            else
                return y>z?y:z;
        }

        int maxPathSum(TreeNode *root)
        {
            int l, r, t;
            if (!root->left && !root->right)
                return root->val;
            if (root->left)
                l = maxPathSum(root->left);
            if (root->right)
                r = maxPathSum(root->right);
            
            if (!root->left) 
                t = r;
            else if (!root->right)
                t = l;
            else
                ;

            int sum = root->val + t;
            if (sum > root->val)
                return sum > t ? sum : t;
            else
                return root->val > t ? root->val : t;
        }

        /*Level Tree*/
        vector<vector<int> > levelOrder(TreeNode *root) {
            vector<TreeNode *> S;

            vector<vector<int> > res;

            if (root == NULL) return res;

            S.push_back(root);

            while(!S.empty()) {
                vector<int> t;
                int n = S.size();
                while (n){
                    TreeNode * node = S.at(S.size() - 1);
                    t.push_back(node->val);
                    S.pop_back();
                    if (node->left)
                        S.insert(S.begin(), node->left);
                    if (node->right)
                        S.insert(S.begin(), node->right);
                    n--;
                }

                res.push_back(t);
            }

            return res;
        }

        vector<vector<int> > levelOrder2(TreeNode *root) {
            vector<TreeNode *> S;

            vector<vector<int> > res;

            if (root == NULL) return res;

            S.push_back(root);

            while(!S.empty()) {
                vector<int> t;
                int n = S.size();
                while (n){
                    TreeNode * node = S.at(S.size() - 1);
                    t.push_back(node->val);
                    S.pop_back();
                    if (node->left)
                        S.insert(S.begin(), node->left);
                    if (node->right)
                        S.insert(S.begin(), node->right);
                    n--;
                }

                res.insert(res.begin(), t);
            }

            return res;
        }

        vector<vector<int> > levelOrder3(TreeNode *root) {
            vector<TreeNode *> S;
            vector<vector<int> > res;
            int flag = 0;

            if (root == NULL) return res;

            S.push_back(root);
            flag = 1;
            while(!S.empty()) {
                vector<int> t;
                vector<TreeNode *> cur;
                int n = S.size();
                while (n){
                    TreeNode * node = S.at(S.size() - 1);
                    if (flag == 1)
                        t.push_back(node->val);
                    else
                        t.insert(t.begin(), node->val);
                    S.pop_back();
                    if (node->left)
                        S.insert(S.begin(), node->left);
                    if (node->right)
                        S.insert(S.begin(), node->right);
                    n--;
                }
                flag = (flag + 1) % 2;
                res.push_back(t);
            }

            return res;
        }
        int _sumNumbers(TreeNode *root, int n) {
            int l = 0, r = 0;
            if (root == NULL) return 0;
            if (root->left == NULL && root->right == NULL)
                return n * 10 + root->val;
            if (root->left)
                l = _sumNumbers(root->left, n * 10 + root->val);
            if (root->right)
                r = _sumNumbers(root->right, n * 10 + root->val);

            return l + r;
        }

        int sumNumbers(TreeNode *root) {
            return _sumNumbers(root, 0);
        }

};

int main() {
    /* Constructed binary tree is
       10
       /   \
       8    2
       / \  /
       3  5 4
       ref from: http://www.geeksforgeeks.org/iterative-preorder-traversal/

     */
    vector<int> pre, in, post;

    /*
         int p[] =
         int i[] =
         for (int j = 0; j < 3000; j++){
         pre.push_back(p[j]);
         in.push_back(i[j]);
         }
     */
    pre.push_back(10);
    pre.push_back(8);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(2);
    pre.push_back(4);

    in.push_back(3);
    in.push_back(8);
    in.push_back(5);
    in.push_back(10);
    in.push_back(4);
    in.push_back(2);

    post.push_back(3);
    post.push_back(5);
    post.push_back(8);
    post.push_back(4);
    post.push_back(2);
    post.push_back(10);

    /*
       pre.push_back(1);
       pre.push_back(2);
       pre.push_back(3);
       in.push_back(1);
       in.push_back(3);
       in.push_back(2);
     */

    Solution S;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
/*    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

root = S.buildTree2(in, post); 
*/
    vector<int> res = S.preorderTraversal(root);
    cout << "pre order :";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout <<endl;

    res = S.inorderTraversal_recursive(root);
    cout << "in order : ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;


    res = S.postorderTraversal(root);
    cout << "post order :";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;


    if (S.hasPathSum(root, 21))
        cout <<"has this path" <<endl;
    vector<vector<int> > r = S.pathSum(root, 21);

    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[0].size(); j++) {
            cout << r[i][j] << " ";
        }
    }
    cout << endl;

    if (S.isSymmetric(root))
        cout <<"Symmetric tree" <<endl;
    else
        cout <<"Not Symmetric tree" <<endl;


    /*--------------------------------------------------------*/
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    root = S.sortedArrayToBST(num);

    res = S.preorderTraversal(root);
    cout << "pre order :";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout <<endl;

    res = S.inorderTraversal(root);
    cout << "in order : ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    vector<vector<int> > level_res;
    level_res = S.levelOrder3(root);
    cout << "level order : ";
    for (int i = 0; i < level_res.size(); i++){
        for (int j = 0; j < level_res[i].size(); j ++)
            cout << level_res[i][j] << " ";

        cout <<endl;
    }

    cout << endl;

    if (S.isValidBST(root))
        cout <<"IS BST"<<endl;
    else
        cout <<"Not BST Tree" <<endl;
    
    cout << "Sum number is " << S.sumNumbers(root) <<endl;
    return 0;
}
