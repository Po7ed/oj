#include <cstdio>

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

long long readl() {
    long long x = 0, f = 1;
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

long long gcd(long long a, long long b) { return (!b) ? a : gcd(b, a % b); }
int n, cnt1, cnt2, q;
long long a[1000005], tail[1000005], now;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = readl();
    q = read();
    while (q--) {
        int l = read(), r = read();
        if (l > cnt1) {
            cnt1 = cnt2 = r;
            now = 0;
            tail[r] = a[r];
            for (int i = r - 1; i >= l; i--) tail[i] = gcd(tail[i + 1], a[i]);
            printf("%lld\n", tail[l] % 11);
        } else {
            for (int i = cnt2 + 1; i <= r; i++) now = gcd(now, a[i]);
            cnt2 = r;
            printf("%lld\n", gcd(tail[l], now) % 11);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long gcds[N];
long long gcd(long long a, long long b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}
long long suffix[N];
int main() {
    int N, M, id;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%lld", gcds + i);
    scanf("%d", &M);
    int l0, r0;
    scanf("%d%d", &l0, &r0);
    long long ans = gcds[l0];
    for (int i = l0 + 1; i <= r0; i++) ans = gcd(gcds[i], ans);
    long long rgcd = ans;
    printf("%lld\n", ans % 11);
    int split = l0;
    for (int i = 2; i <= M; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > split) {
            split = r;
            suffix[split - 1] = gcds[split - 1];
            for (int j = split - 2; j >= l; j--) suffix[j] = gcd(suffix[j + 1], gcds[j]);
            rgcd = gcds[r];
        } else {
            for (int j = r0 + 1; j <= r; j++) rgcd = gcd(rgcd, gcds[j]);
        }
        if (l == split)
            printf("%lld\n", rgcd % 11);
        else
            printf("%lld\n", gcd(rgcd, suffix[l]) % 11);
        l0 = l;
        r0 = r;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long gcds[N];
long long gcd(long long a, long long b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}
long long suffix[N];
int main() {
    int N, M, id;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%lld", gcds + i);
    scanf("%d", &M);
    int l0, r0;
    scanf("%d%d", &l0, &r0);
    long long ans = gcds[l0];
    for (int i = l0 + 1; i <= r0; i++) ans = gcd(gcds[i], ans);
    long long rgcd = ans;
    printf("%lld\n", ans % 11);
    int split = l0;
    for (int i = 2; i <= M; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > split) {
            split = r;
            suffix[split - 1] = gcds[split - 1];
            for (int j = split - 2; j >= l; j--) suffix[j] = gcd(suffix[j + 1], gcds[j]);
            rgcd = gcds[r];
        } else {
            for (int j = r0 + 1; j <= r; j++) rgcd = gcd(rgcd, gcds[j]);
        }
        if (l == split)
            printf("%lld\n", rgcd % 11);
        else
            printf("%lld\n", gcd(rgcd, suffix[l]) % 11);
        l0 = l;
        r0 = r;
    }
    return 0;
}