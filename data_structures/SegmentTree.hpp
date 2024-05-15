#include<vector>
using namespace std;

// セグメント木[0,n)について区間の総和を取得
// update(i,x): i番目の要素をxに更新 O(logN)
// query(a,b): [a,b)での総和を取得 O(logN)

template <typename T> class SegmentTree {
  private:
    int n;
    vector<T> dat;
    T unit;
    function<T(T, T)> op;

  public:
    SegmentTree(int n_, T unit_, function<T(T, T)> op_)
        : n(), dat(n_ * 4, unit_), unit(unit_), op(op_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return unit;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return op(vl, vr);
        }
    }
    T get(int a) { return query(a, a + 1); }
};

int e() { return 0; }
int op(int a, int b) { return a + b; }