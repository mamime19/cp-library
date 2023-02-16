#include<vector>
#include<queue>
#include<utility>
using namespace std;

struct edge {
    int from, to;
    long long cost;
};
long long d[250010];
vector<edge> G[250010];

// Dijkstra Algorithm
// s→iの最短距離をd[i]で取得できる

void Dijkstra(int s) {
    using P = pair<long long, int>;
    priority_queue<P, vector<P>, std::greater<P>> que;
    fill(d, d + 250010, 3e18);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (int i = 0; i < (signed)G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}