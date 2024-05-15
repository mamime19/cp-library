#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Dijkstra {
  private:
    struct edge {
        int from, to;
        long long cost;
    };
    int n;
    vector<long long> dist;
    vector<vector<edge>> G;

  public:
    Dijkstra(int n_) : n(), dist(n_), G(n_) {}
    void add_edge(int u, int v, long long w) {
        edge e;
        e.to = v, e.cost = w;
        G[u].push_back(e);
        e.to = u;
        G[u].push_back(e);
    }
    void build(int s) {
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, std::greater<P>> que;
        fill(dist.begin(), dist.end(), 3e18);
        dist[s] = 0;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (int i = 0; i < (signed)G[v].size(); i++) {
                edge e = G[v][i];
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
    }
    long long get(int v){
        return dist[v];
    }
};