#include <vector>
using namespace std;

struct edge {
    int to, from;
    long long cost;
};

int N, M;
long long d[2010];
vector<edge> G;

// Bellman-Ford Algorithm
// d[i]が-INFであるときs→iの最短経路に負閉路が含まれる

void Bellman_Ford(int s) {
    for (int i = 0; i < N; i++) {
        d[i] = 3e18;
    }
    d[s] = 0;
    for (int i = 0; i < N * 2; i++) {
        for (int j = 0; j < M; j++) {
            edge e = G[j];
            if (d[e.from] != 3e18 && d[e.to] > d[e.from] + e.cost) {
                if (i >= N - 1) {
                    d[e.to] = -3e18;
                } else {
                    d[e.to] = d[e.from] + e.cost;
                }
            }
        }
    }
}