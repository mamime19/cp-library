#include<iostream>
using namespace std;

constexpr long long mod = 1000000007;
// constexpr long long mod=998244353;

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