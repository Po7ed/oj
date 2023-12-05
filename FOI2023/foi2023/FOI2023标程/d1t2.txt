#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
const int mod = 11;
int n, m, id;
int dp[N][22];
// dp[i][j]表示从i到2的j次方-1的最小值
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int answer(int l, int r) {
    int k = log2(r - l + 1);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int main() {
    n = read();
    id = read();
    for (int i = 1; i <= n; i++) {
        dp[i][0] = read();
    }
    for (int j = 1; j <= 21; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    m = read();
    for (int i = 1; i <= m; i++) {
        int l, r;
        l = read();
        r = read();
        printf("%d\n", answer(l, r) % mod);
    }
    return 0;
}


#include <cstdio>
#include <algorithm>
int read() {
    int x = 0, f = 1;
    char ac = getchar();
    while (ac < '0' || ac > '9') {
        if (ac == '-')
            f = -1;
        ac = getchar();
    }
    while (ac >= '0' && ac <= '9') {
        x = (x << 3) + (x << 1) + (ac - '0');
        ac = getchar();
    }
    return x * f;
}
int maxn[1000005][20], n, q, logg[1000005], id;
int query(int l, int r) {
    int sum = logg[r - l + 1];
    return std::max(maxn[l][sum], maxn[r - (1 << sum) + 1][sum]);
}
int main() {
    n = read(), id = read();
    for (int i = 1; i <= n; i++) maxn[i][0] = read();
    logg[1] = 0;
    for (int i = 2; i <= n; i++) logg[i] = logg[i / 2] + 1;
    for (int i = 1; i <= logg[n]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            maxn[j][i] = std::max(maxn[j][i - 1], maxn[j + (1 << (i - 1))][i - 1]);
        }
    }
    q = read();
    while (q--) {
        int l = read(), r = read();
        printf("%d\n", query(l, r) % 11);
    }
    return 0;
}