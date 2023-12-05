#include <cstdio>
#include <cstring>
#define maxn 20005
#define maxm 200005
using namespace std;
int n, m, k, a, b, c, x, num, head, tail, ans, sta;
int to[maxm * 2], next[maxm * 2], first[maxn], weight[maxm * 2], limit[maxn], q[maxn], dis[maxn], dis1[22],
    floyd[25][25], f[(1 << 21) + 1][22];
bool inq[maxn];
int min(int a1, int b1) { return a1 < b1 ? a1 : b1; }
void add(int l, int g, int j) {
    to[++num] = g;
    weight[num] = j;
    next[num] = first[l];
    first[l] = num;
}
void spfa(int start) {
    dis[start] = 0;
    inq[start] = 1;
    q[++tail] = start;
    while (head != tail) {
        head++;
        if (head > n + 1)
            head = 0;
        int temp = q[head];
        inq[temp] = 0;
        for (int i = first[temp]; i; i = next[i]) {
            int temp2 = dis[temp] + weight[i];
            if (dis[to[i]] > temp2) {
                dis[to[i]] = temp2;
                if (!inq[to[i]]) {
                    ++tail;
                    if (tail > n + 1)
                        tail = 0;
                    q[tail] = to[i];
                    inq[to[i]] = 1;
                }
            }
        }
    }
}
int aa, ch;
int main() {
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
        scanf("%d%d", &a, &b);
        limit[b] |= 1 << (a - 1);
    }
    for (int i = 1; i <= k + 1; i++) {
        memset(dis, 127, sizeof(dis));
        head = tail = 0;
        spfa(i);
        for (int j = 1; j <= k + 1; j++) floyd[i][j] = dis[j];
        dis1[i] = dis[n];
    }
    memset(f, 127, sizeof(f));
    for (int i = 1; i <= k + 1; i++) f[(1 << (i - 1)) | 1][i] = floyd[1][i];
    sta = (1 << (k + 1)) - 1;
    for (int i = 1; i <= sta; i += 2)
        for (int j = 2; j <= k + 1; j++) {
            int j1 = 1 << (j - 1);
            if (i & j1 && ((i & limit[j]) == limit[j]))
                for (int b = 1; b <= k + 1; b++) {
                    int b1 = 1 << (b - 1);
                    if (b != j && i & b1 && ((i - j1) & limit[b]) == limit[b])
                        f[i][j] = min(f[i][j], f[i - j1][b] + floyd[b][j]);
                }
        }
    ans = 0x7ffffff;
    if (k == 0)
        return !printf("%d", dis1[1]);
    for (int i = 2; i <= k + 1; i++) ans = min(ans, f[sta][i] + dis1[i]);
    printf("%d", ans);
    return 0;
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
int n, m, k, cnt, tot, ans = 0x3f3f3f3f;
int dis[20010], vis[20010], op[20010];
int h[20010], dp[1 << 22][23], f[20010][20010], c[30];
struct node {
    int to, nxt, w;
} e[400010];
void add(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].nxt = h[u];
    e[cnt].w = w;
    h[u] = cnt;
}
struct com {
    int v, w;
    friend bool operator<(com a, com b) { return a.w > b.w; }
} tmp;
void dijkstra(int s) {
    priority_queue<com> q;
    for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f, vis[i] = 0;
    dis[s] = 0;
    tmp.v = s, tmp.w = 0;
    q.push(tmp);
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = h[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                tmp.v = v, tmp.w = dis[v];
                q.push(tmp);
            }
        }
    }
    for (int i = 1; i <= n; i++) f[s][i] = f[i][s] = dis[i];
}
int main() {
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= k + 1; i++) {
        c[++tot] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        add(u, v, w), add(v, u, w);
    }
    for (int i = 1; i <= tot; i++) dijkstra(c[i]), op[c[i]] = 1;
    int x = read();
    for (int i = 1; i <= x; i++) {
        int a = read(), b = read();
        op[b] = op[b] | (1 << (a - 1));
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    //	cout << tot << endl;
    //	cout << f[3][4] << endl;
    for (int s = 1; s < (1 << tot); s++) {
        if (!(s & 1))
            continue;
        for (int i = 1; i <= tot; i++) {
            int u = c[i];
            //			if(dp[s][u] == 0x3f3f3f3f) continue;
            if ((1 << (u - 1)) & s && ((op[u] & s) == op[u])) {
                for (int j = 1; j <= tot; j++) {
                    int v = c[j];
                    if (i == j)
                        continue;
                    //					cout << op[v] << " " << s << " " << u << " " << v <<
                    //endl;
                    if (((op[v] & s) == op[v])) {
                        //						cout << s << " " << u << " " << v << " " << (s |
                        //(1 << (v - 1))) << " " << dp[s][u] << " " << f[u][v] << " ";
                        dp[s | (1 << (v - 1))][v] = min(dp[s | (1 << (v - 1))][v], dp[s][u] + f[u][v]);
                        //						cout << dp[s | (1 << (v - 1))][v] <<
                        //endl;
                    }
                }
            }
        }
    }
    if (!k) {
        cout << f[1][n] << endl;
        return 0;
    }
    for (int i = 2; i <= tot; i++) ans = min(ans, dp[(1 << tot) - 1][c[i]] + f[c[i]][n]);
    cout << ans << endl;
    return 0;
}


