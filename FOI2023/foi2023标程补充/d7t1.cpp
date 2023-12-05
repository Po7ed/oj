#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#ifdef DEBUG
#include <fstream>
using std::cerr;
std::ifstream in("in.in", std::ifstream::in);
std::ofstream out("out.out", std::ofstream::out);
std::ofstream err("err.out", std::ofstream::out);
#endif
using std::cin;
using std::cout;
using std::ios;
using std::string;
using ull = unsigned long long;
const int N = 1e6 + 7;
const int MOD = 919260817;
const int BASE = 233;
ull pw[N];
ull hsh[8][N];
void init_power(int n) {
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * BASE;
    }
}

void set_hash(int num, const string &s) {
    for (int i = 0; i < s.length(); ++i) {
        hsh[num][i] = hsh[num][i - 1] * BASE + s[i];
    }
}

ull hash(int num, int l, int r) { return hsh[num][r] - hsh[num][l - 1] * pw[r - l + 1]; }

int len[100];
int cnt[7];
string str[8];
int fib[700], lt[700], hd[700];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifdef DEBUG
    auto st_t = clock();
    cin.rdbuf(in.rdbuf()), cout.rdbuf(out.rdbuf()), cerr.rdbuf(err.rdbuf());
#endif
    string s1, s2, m, st;
    int n;
    init_power(1e6);
    cin >> n;
    cin >> s1 >> s2 >> m;
    while (true) {
        if (s1.size() > m.size() && s2.size() > m.size()) {
            break;
        }
        st = s2;
        s2 = s1 + s2;
        s1 = st;
        n--;
    }
    str[1] = s1;
    str[2] = s2;
    str[3] = s1 + s2;
    str[4] = s1 + s1;
    str[5] = s2 + s1;
    str[6] = s2 + s2;
    str[7] = m;
    for (int i = 1; i <= 7; ++i) {
        set_hash(i, str[i]);
    }
    for (int k = 1; k <= 6; ++k) {
        for (int i = 0; i < str[k].size(); ++i) {
            if (str[k][i] == str[7][0] &&
                hash(k, i, i + str[7].length() - 1) == hash(7, 0, str[7].length() - 1)) {
                cnt[k]++;
            }
            cnt[k] %= MOD;
        }
        cnt[k] %= MOD;
    }

    fib[1] = cnt[1], fib[2] = cnt[2];
    hd[1] = 1, lt[1] = 1;
    hd[2] = 2, lt[2] = 2;
    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
        fib[i] %= MOD;
        hd[i] = hd[i - 2];
        lt[i] = lt[i - 1];
        if (hd[i - 1] == 1) {
            if (lt[i - 2] == 1) {  // s1 s1
                fib[i] += cnt[4] - cnt[1] * 2;
            } else {  // s2 s1
                fib[i] += cnt[5] - cnt[1] - cnt[2];
            }
        } else {
            if (lt[i - 2] == 1) {  // s1 s2
                fib[i] += cnt[3] - cnt[1] - cnt[2];
            } else {  // s2 s1
                fib[i] += cnt[6] - cnt[2] - cnt[2];
            }
        }
        fib[i] %= MOD;
        // cout << fib[i] << "\n";
    }
    cout << fib[n] << "\n";
#ifdef DEBUG
    cerr << clock() - st_t << "\n";
#endif
    return 0;
}


#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#ifdef DEBUG
#include <fstream>
using std::cerr;
std::ifstream in("in.in", std::ifstream::in);
std::ofstream out("out.out", std::ofstream::out);
std::ofstream err("err.out", std::ofstream::out);
#endif
using std::cin;
using std::cout;
using std::ios;
using std::string;
using ull = unsigned long long;
const int N = 1e6 + 7;
const int MOD = 919260817;
const int BASE = 233;
ull pw[N];
ull hsh[8][N];
void init_power(int n) {
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * BASE;
    }
}

void set_hash(int num, const string &s) {
    for (int i = 0; i < s.length(); ++i) {
        hsh[num][i] = hsh[num][i - 1] * BASE + s[i];
    }
}

ull hash(int num, int l, int r) { return hsh[num][r] - hsh[num][l - 1] * pw[r - l + 1]; }

int len[100];
int cnt[7];
string str[8];
int fib[700], lt[700], hd[700];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifdef DEBUG
    auto st_t = clock();
    cin.rdbuf(in.rdbuf()), cout.rdbuf(out.rdbuf()), cerr.rdbuf(err.rdbuf());
#endif
    string s1, s2, m, st;
    int n;
    init_power(1e6);
    cin >> n;
    cin >> s1 >> s2 >> m;
    while (true) {
        if (s1.size() > m.size() && s2.size() > m.size()) {
            break;
        }
        st = s2;
        s2 = s1 + s2;
        s1 = st;
        n--;
    }
    str[1] = s1;
    str[2] = s2;
    str[3] = s1 + s2;
    str[4] = s1 + s1;
    str[5] = s2 + s1;
    str[6] = s2 + s2;
    str[7] = m;
    for (int i = 1; i <= 7; ++i) {
        set_hash(i, str[i]);
    }
    for (int k = 1; k <= 6; ++k) {
        for (int i = 0; i < str[k].size(); ++i) {
            if (str[k][i] == str[7][0] &&
                hash(k, i, i + str[7].length() - 1) == hash(7, 0, str[7].length() - 1)) {
                cnt[k]++;
            }
            cnt[k] %= MOD;
        }
        cnt[k] %= MOD;
    }

    fib[1] = cnt[1], fib[2] = cnt[2];
    hd[1] = 1, lt[1] = 1;
    hd[2] = 2, lt[2] = 2;
    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
        fib[i] %= MOD;
        hd[i] = hd[i - 2];
        lt[i] = lt[i - 1];
        if (hd[i - 1] == 1) {
            if (lt[i - 2] == 1) {  // s1 s1
                fib[i] += cnt[4] - cnt[1] * 2;
            } else {  // s2 s1
                fib[i] += cnt[5] - cnt[1] - cnt[2];
            }
        } else {
            if (lt[i - 2] == 1) {  // s1 s2
                fib[i] += cnt[3] - cnt[1] - cnt[2];
            } else {  // s2 s1
                fib[i] += cnt[6] - cnt[2] - cnt[2];
            }
        }
        fib[i] %= MOD;
        // cout << fib[i] << "\n";
    }
    cout << fib[n] << "\n";
#ifdef DEBUG
    cerr << clock() - st_t << "\n";
#endif
    return 0;
}

