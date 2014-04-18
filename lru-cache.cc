#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>



using namespace std;
struct DouLinkNode {
    pair<int, int> val;
    DouLinkNode *prev, *next;
    DouLinkNode (int k, int v) : val(make_pair(k, v)), prev(NULL), next(NULL) {}
};


class LRUCache{
    int N;
    int size;
    unordered_map<int, DouLinkNode*> k2node;
    DouLinkNode *head, *tail;
  public:
    LRUCache(int capacity) {
        N = capacity;
        size = 0;
        head = tail = NULL;
    }

    void insertNode(DouLinkNode *node){
        if (head == NULL)
            tail = head = node;
        else{
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void delNode(DouLinkNode *node){
        if (head == tail){
            head = tail = NULL;
            return ;
        }

        if (node == head)
            head = node->next;
        else if (node == tail)
            tail = node->prev;
        else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->next = node->prev = NULL;
    }

    int find(int k) {
        auto it = k2node.find(k);
        if (it == k2node.end()) return -1;
        DouLinkNode *node = it->second;

        delNode(node);
        insertNode(node);

        return node->val.second;
    }

    int get(int key) {
        return find(key);     
    }

    void set(int key, int value) {
        auto it = k2node.find(key);
        DouLinkNode * node ;

        if (it == k2node.end() && size < N){
            node = new DouLinkNode(key, value);
            size++;
        } else {
            if (it != k2node.end()){
                node = it->second;
            } else
                node = tail;
            k2node.erase(node->val.first);
            delNode(node);
            node->prev = NULL;
            node->val.first= key;
            node->val.second = value;
        }
        insertNode(node);
        k2node[key] = node;

    }

    void show(){
        cout << "----" <<endl;
        DouLinkNode *p = head;

        while (1){
            cout <<"key: " << p->val.first<< "value:" <<  p->val.second<<endl;
            if (p == tail) break;
            p = p->next;
        }
        cout << "----" <<endl;
    }
};


int main()
{
/*       LRUCache S(4);

       S.set(1,1);
       S.set(2,2);
       S.set(3,3);
       S.set(3,10);
       S.set(4,4);
       S.show();
       S.set(9,4);
       S.show();

       cout <<S.get(2) <<endl;;
       S.show();
       cout <<S.get(100) <<endl;;
       S.show();
*/
    LRUCache S(1);
    S.set(2,1);
    cout <<S.get(2)<<endl;
    S.set(3,2);
    cout <<S.get(2)<<endl;

       return 0;
}
