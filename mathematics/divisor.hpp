#include<vector>
using namespace std;

vector<long long> div(long long n) {
    vector<long long> v;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i * i != n) {
                v.push_back(n / i);
            }
        }
    }
    return v;
}
