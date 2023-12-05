#include <bits/stdc++.h>
using namespace std;

#define maxn 1005
#define maxm 100005
#define maxd 40000
#define int long long

int fa[maxd][maxn], times[maxd];

int n, m;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int find(int u, int v) {
    if (fa[u][v] == 0)
        return v;
    return fa[u][v] = find(u, fa[u][v]);
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1, u, v, w, x, y; i <= m; i++) {
        scanf("%lld%lld%lld", &u, &v, &w);
        for (int j = 1; j * j <= w; j++) {
            if (w % j == 0) {
                x = find(j, u);
                y = find(j, v);
                if (x != y) {
                    fa[j][x] = y;
                    times[j]++;
                }
                int t = w / j;
                x = find(t, u);
                y = find(t, v);
                if (x != y) {
                    fa[t][x] = y;
                    times[t]++;
                }
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= 32768; i++)
        if (times[i] == n - 1)
            ans = ans / gcd(ans, i) * i;
    printf("%lld", ans);
}


#include <bits/stdc++.h>
using namespace std;

#define maxn 1005
#define maxm 100005
#define maxd 40000
#define int long long

int fa[maxd][maxn], times[maxd];

int n, m;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int find(int u, int v) {
    if (fa[u][v] == 0)
        return v;
    return fa[u][v] = find(u, fa[u][v]);
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1, u, v, w, x, y; i <= m; i++) {
        scanf("%lld%lld%lld", &u, &v, &w);
        for (int j = 1; j * j <= w; j++) {
            if (w % j == 0) {
                x = find(j, u);
                y = find(j, v);
                if (x != y) {
                    fa[j][x] = y;
                    times[j]++;
                }
                int t = w / j;
                x = find(t, u);
                y = find(t, v);
                if (x != y) {
                    fa[t][x] = y;
                    times[t]++;
                }
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= 32768; i++)
        if (times[i] == n - 1)
            ans = ans / gcd(ans, i) * i;
    printf("%lld", ans);
}