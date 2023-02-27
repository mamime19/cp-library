#include<deque>
#include<vector>
using namespace std;

int N;
int H[200010];
vector<int> G[200010];
deque<int> que;
vector<int> T;
// DAGはT.size()==vで判定

void Topologic() {
    for (int i = 0; i < N; i++) {
        if (H[i] == 0) {
            que.push_back(i);
        }
    }
    while (que.size()) {
        int i = que.front();
        que.pop_front();
        T.push_back(i);
        for (auto j : G[i]) {
            H[j]--;
            if (H[j] == 0) {
                que.push_back(j);
            }
        }
    }
}