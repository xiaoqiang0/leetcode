#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <set>
using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        vector<UndirectedGraphNode *> v;
        queue<UndirectedGraphNode *> Q;

        if (node == NULL) return NULL;

        Q.push(node);
        v.push_back(node);
        while (!Q.empty()) {
            UndirectedGraphNode *p = Q.front();

            vector<UndirectedGraphNode *>  n = p->neighbors;

            for (int i = 0; i < n.size(); i++){
                if (find(v.begin(), v.end(), n[i]) == v.end()){
                    v.push_back(n[i]);
                    Q.push(n[i]);
                }
            }
            Q.pop();
        }

        map<UndirectedGraphNode*, int>add2idx;
        vector<vector<int> >idx2nei(v.size(), vector<int>());
        vector<UndirectedGraphNode *> idx2add;

        for (int i = 0; i < v.size(); i ++){
            add2idx[v[i]] = i;
        }

        for (int i = 0; i < v.size(); i ++){
            vector<UndirectedGraphNode *> &n = v[i]->neighbors;
            for (int j = 0; j < n.size(); j++){
                idx2nei[i].push_back(add2idx[n[j]]);
            }
        }


        for (int i = 0; i < v.size(); i++){
            idx2add.push_back(new UndirectedGraphNode(v[i]->label));
        }

        for (int i = 0; i < v.size(); i++){
            vector<int> &nei = idx2nei[i];
            for (int j = 0; j < nei.size(); j++)
                idx2add[i]->neighbors.push_back(idx2add[nei[j]]);
        }

        return idx2add[0];
    }
};
int main()
{
    /*UndirectedGraphNode *node = new UndirectedGraphNode(1);
    node->neighbors.push_back(new UndirectedGraphNode(0));
    node->neighbors.push_back(new UndirectedGraphNode(2));

    node->neighbors[0]->neighbors.push_back(node);
    node->neighbors[0]->neighbors.push_back(node->neighbors[1]);
    
    node->neighbors[1]->neighbors.push_back(node);
    node->neighbors[1]->neighbors.push_back(node->neighbors[0]);
    node->neighbors[1]->neighbors.push_back(node->neighbors[1]);
*/
    vector<UndirectedGraphNode *> G;

    G.push_back(new UndirectedGraphNode(-3)); //0
    G.push_back(new UndirectedGraphNode(-1)); //1
    G.push_back(new UndirectedGraphNode(2));  //2
    G.push_back(new UndirectedGraphNode(3));  //3
    G.push_back(new UndirectedGraphNode(5));  //4
    G[0]->neighbors.clear();
    G[0]->neighbors.push_back(G[1]);
    G[0]->neighbors.push_back(G[3]);
    G[0]->neighbors.push_back(G[4]);



    G[1]->neighbors.clear();
    G[1]->neighbors.push_back(G[2]);
    G[1]->neighbors.push_back(G[3]);
    G[1]->neighbors.push_back(G[3]);

    G[2]->neighbors.clear();
    G[2]->neighbors.push_back(G[3]);


    G[3]->neighbors.clear();
    G[3]->neighbors.push_back(G[4]);

    G[4]->neighbors.clear();


    Solution S;
    S.cloneGraph(G[0]);
    return 0;
}
