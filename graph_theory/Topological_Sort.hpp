#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

class TopologicalSort {
  public:
    int V;
    vector<vector<int>> G;
    vector<int> deg, res;
    TopologicalSort(int node_size) : V(node_size), G(V), deg(V, 0) {}
    void add_edge(int from, int to) {
        G[from].push_back(to);
        deg[to]++;
    }
    bool solve() {
        deque<int> que;
        for (int i = 0; i < V; i++) {
            if (deg[i] == 0) {
                que.push_back(i);
            }
        }
        while (!que.empty()) {
            int p = que.front();
            que.pop_front();
            res.push_back(p);
            for (int v : G[p]) {
                deg[v]--;
                if (deg[v] == 0) {
                    que.push_back(v);
                }
            }
        }
        return (*max_element(deg.begin(), deg.end()) == 0);
    }
};