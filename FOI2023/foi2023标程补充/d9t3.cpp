#include <iostream>
#include <cstdio>
using namespace std;

#define maxn 1000005

int n, cnt, fa;
int c[maxn];
int head[maxn << 1], to[maxn << 1], nxt[maxn << 1], tot;
long long f[maxn], minn[maxn];

void add(int x, int y) {
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int u) {
    long long res = 0;
    for (int i = head[u], y; i; i = nxt[i]) {
        y = to[i];
        dfs(y);
        f[u] += f[y];
        minn[u] = min(minn[u], minn[y]);
        res = res + c[y];
    }
    if (c[u] > res)
        f[u] += (c[u] - res) * minn[u];
    else
        c[u] = res;
}
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%lld", &fa, &c[i], &minn[i]);
        add(fa, i);
    }
    dfs(1);
    printf("%lld", f[1]);
}




#include <iostream>
#include <cstdio>
using namespace std;

#define maxn 1000005

int n, cnt, fa;
int c[maxn];
int head[maxn << 1], to[maxn << 1], nxt[maxn << 1], tot;
long long f[maxn], minn[maxn];

void add(int x, int y) {
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}

void dfs(int u) {
    long long res = 0;
    for (int i = head[u], y; i; i = nxt[i]) {
        y = to[i];
        dfs(y);
        f[u] += f[y];
        minn[u] = min(minn[u], minn[y]);
        res = res + c[y];
    }
    if (c[u] > res)
        f[u] += (c[u] - res) * minn[u];
    else
        c[u] = res;
}
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%lld", &fa, &c[i], &minn[i]);
        add(fa, i);
    }
    dfs(1);
    printf("%lld", f[1]);
}


#include <bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + (c - '0');
        c = getchar();
    }
    return x * f;
}
int n, cnt;
int h[1000010], minn[1000010], c[1000010], t[1000010];
long long ans[1000010], sum[1000010];
struct node {
    int to, nxt;
} e[1000010];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = h[u];
    h[u] = cnt;
}
void dfs(int u, int fa) {
    minn[u] = t[u];
    //	cout << u << " " << h[u] << endl;
    for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
        minn[u] = min(minn[u], minn[v]);
        sum[u] += sum[v];
        ans[u] += ans[v];
    }
    if (sum[u] < c[u])
        ans[u] += minn[u] * (c[u] - sum[u]), sum[u] = c[u];
    //	cout << u << " " << sum[u] << " " << minn[u] << " " << ans[u] << endl;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int u = read();
        c[i] = read(), t[i] = read();
        add(u, i);
    }
    dfs(1, 0);
    cout << ans[1] << endl;
    return 0;
}