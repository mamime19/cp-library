#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Number {
  private:
    long long num;

  public:
    Number(long long x = 0) { num = x; }
    // 素数判定
    // O(√N)で判定
    bool is_prime() {
        if (num == 1) {
            return false;
        }
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    // 約数列挙
    // O(√N)で列挙
    vector<long long> divisor() {
        vector<long long> res;
        for (long long i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                res.push_back(i);
                if (i * i != num) {
                    res.push_back(num / i);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    // 素因数分解
    // O(√N)で列挙
    vector<pair<long long, long long>> prime_factor() {
        vector<pair<long long, long long>> res;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i != 0) {
                continue;
            }
            long long tmp = 0;
            while (num % i == 0) {
                tmp++;
                num /= i;
            }
            res.push_back({i, tmp});
        }
        if (num != 1) {
            res.push_back({num, 1});
        }
        return res;
    }
};