#include <bits/stdc++.h>
using namespace std;

// constexpr long long mod = 1000000007;
constexpr long long mod = 998244353;

class mint {
  private:
    long long x;

  public:
    constexpr mint(long long x = 0) : x((x % mod + mod) % mod) {}
    constexpr mint &operator+=(const mint &a) {
        x += a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    constexpr mint &operator-=(const mint &a) {
        x += mod - a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    constexpr mint &operator*=(const mint &a) {
        x *= a.x;
        x %= mod;
        return *this;
    }
    constexpr mint operator+(const mint &a) const {
        mint res(*this);
        return res += a;
    }
    constexpr mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }
    constexpr mint operator*(const mint &a) const {
        mint res(*this);
        return res *= a;
    }
    constexpr mint pow(long long r) const {
        if (r == 0)
            return 1;
        mint a = pow(r >> 1);
        a *= a;
        if (r & 1)
            a *= *this;
        return a;
    }
    constexpr mint comb(long long n, long long r) const {
        mint a = 1;
        for (int i = 1; i <= r; i++) {
            a *= n - i + 1;
            a /= i;
        }
        return a;
    }
    // 素数のときのみ使用可能
    constexpr mint inv() const { return pow(mod - 2); }
    constexpr mint &operator/=(const mint &a) { return (*this) *= a.inv(); }
    constexpr mint operator/(const mint &a) const {
        mint res(*this);
        return res /= a;
    }
    friend ostream &operator<<(ostream &os, const mint &m) {
        os << m.x;
        return os;
    }
};

class BiominalCoefficient {
  private:
    vector<mint> fact;
    vector<mint> finv;
    vector<mint> inv;

  public:
    BiominalCoefficient(int n) : fact(n), finv(n), inv(n) {
        fact[0] = fact[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < n; i++) {
            fact[i] = fact[i - 1] * i;
            inv[i] = (mint)mod - inv[mod % i] * mint(mod / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    mint get(int n, int k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fact[n] * finv[k] * finv[n - k];
    }
};