#include <vector>
using namespace std;

class UnionFind {
  private:
    vector<int> par; // 各元の親を表す配列
    vector<int> siz; // 素集合のサイズを表す
  public:
    // コンストラクタ
    UnionFind(int sz) : par(sz), siz(sz, 1) {
        for (int i = 0; i < sz; i++)
            par[i] = i; // 親は自分
    }
    int root(int x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // 経路圧縮　xの親の親をxの親とする
        }
        return x;
    }
    bool unite(int x, int y) { // 素集合の併合
        x = root(x), y = root(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y]) { // マージテク
            swap(x, y);
        }
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) { // 連結判定
        return root(x) == root(y);
    }
    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};