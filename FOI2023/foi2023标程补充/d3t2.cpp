#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
    int l, r, setv;
    int maxv;
    long long w;
} e[maxn * 4];
int f[maxn], vis[maxn], g[maxn], h[maxn];
map<int, int> m;
void build(int a, int b, int c) {
    if (a == b) {
        e[c].l = e[c].r = a;
        e[c].w = g[a];
        e[c].maxv = g[a];
        e[c].setv = -1;
        return;
    }
    int mid = (a + b) >> 1;
    build(a, mid, c * 2);
    build(mid + 1, b, c * 2 + 1);
    e[c].l = a;
    e[c].r = b;
    e[c].w = e[c * 2].w + e[c * 2 + 1].w;
    e[c].maxv = max(e[c * 2].maxv, e[c * 2 + 1].maxv);
    e[c].setv = -1;
    return;
}
void pushdown(int c) {
    if (e[c].setv != -1) {
        e[c * 2].setv = e[c * 2 + 1].setv = e[c].setv;
        e[c * 2].maxv = e[c * 2 + 1].maxv = e[c].setv;
        e[c * 2].w = (e[c * 2].r - e[c * 2].l + 1) * e[c].setv;
        e[c * 2 + 1].w = (e[c * 2 + 1].r - e[c * 2 + 1].l + 1) * e[c].setv;
        e[c].setv = -1;
    }
}
void update(int a, int b, int c, int val) {
    if (e[c].l == a && e[c].r == b) {
        e[c].setv = val;
        e[c].w = (b - a + 1) * val;
        e[c].maxv = val;
        return;
    }
    pushdown(c);
    int mid = (e[c].l + e[c].r) / 2;
    if (b <= mid)
        update(a, b, c * 2, val);
    else if (a > mid)
        update(a, b, c * 2 + 1, val);
    else {
        update(a, mid, c * 2, val);
        update(mid + 1, b, c * 2 + 1, val);
    }
    e[c].w = e[c * 2].w + e[c * 2 + 1].w;
    e[c].maxv = max(e[c * 2].maxv, e[c * 2 + 1].maxv);
}
int get(int c, int val) {
    if (e[c].l == e[c].r)
        return e[c].l;
    pushdown(c);
    if (e[c * 2].maxv > val)
        return get(c * 2, val);
    else
        return get(c * 2 + 1, val);
}
int main() {
    freopen("mex.in", "r", stdin);
    freopen("mex.out", "w", stdout);
    int n;
    cin >> n;
    int t = 0, l, r;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        if (f[i] < maxn)
            vis[f[i]] = 1;
        while (vis[t]) t++;
        g[i] = t;
    }
    m.clear();
    for (int i = n; i >= 1; i--) {
        if (m[f[i]] == 0)
            h[i] = n + 1;
        else
            h[i] = m[f[i]];
        m[f[i]] = i;
    }
    build(1, n, 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += e[1].w;
        if (e[1].maxv > f[i]) {
            l = get(1, f[i]);
            r = h[i] - 1;
            if (l <= r)
                update(l, r, 1, f[i]);
        }
        update(i, i, 1, 0);
    }
    cout << ans;
    return 0;
}