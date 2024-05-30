#include <bits/stdc++.h>
using namespace std;
typedef string::const_iterator state;
int expression(state &begin);
int term(state &begin);
int factor(state &begin);
int number(state &begin);

int expression(state &begin) {
    int ret = term(begin);
    for (;;) {
        if (*begin == '+') {
            begin++;
            ret += term(begin);
        } else if (*begin == '-') {
            begin++;
            ret -= term(begin);
        } else {
            break;
        }
    }
    return ret;
}

int term(state &begin) {
    int ret = factor(begin);
    for (;;) {
        if (*begin == '*') {
            begin++;
            ret *= factor(begin);
        } else if (*begin == '/') {
            begin++;
            ret /= factor(begin);
        } else {
            break;
        }
    }
    return ret;
}

int factor(state &begin) {
    for (;;) {
        if (*begin == '(') {
            begin++;
            int ret = expression(begin);
            begin++;
            return ret;
        } else {
            return number(begin);
        }
    }
}

int number(state &begin) {
    int ret = 0;
    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        state begin = s.begin();
        int ans = expression(begin);
        cout << ans << endl;
    }
    return 0;
}
