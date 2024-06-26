#include<bits/stdc++.h>
using namespace std;

class RollingHash {
  private:
    static constexpr int M = 2;
    static constexpr long long MODS[M] = {999999937, 1000000007};
    static constexpr long long BASE = 9973;
    vector<long long> powb[M], hash[M];
    int n;

  public:
    RollingHash() {}
    RollingHash(const string &str) { init(str); }
    void init(const string &str) {
        n = str.size();
        for (int k = 0; k < M; k++) {
            powb[k].resize(n + 1, 1);
            hash[k].resize(n + 1, 0);
            for (int i = 0; i < n; i++) {
                hash[k][i + 1] = (hash[k][i] * BASE + str[i]) % MODS[k];
                powb[k][i + 1] = powb[k][i] * BASE % MODS[k];
            }
        }
    }
    // get hash str[l,r)
    long long get(int l, int r, int k) {
        long long res = hash[k][r] - hash[k][l] * powb[k][r - l] % MODS[k];
        if (res < 0)
            res += MODS[k];
        return res;
    }
};