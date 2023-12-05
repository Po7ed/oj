#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 100005
#define int long long

int n, m, len, cnt, cnt2;
int root[maxn], ls[maxn << 5], rs[maxn << 5];
int a[maxn];
int s[maxn << 5];
int f[maxn << 1][20];
int R[maxn << 1];
int first[maxn], ver[maxn << 1], fa[maxn];
bool flag[maxn];

vector<int> v;
vector<int> v2[maxn];

int Hash(int k) { return lower_bound(v.begin(), v.end(), k) - v.begin() + 1; }

void init(int k, int val, int pre, int &now, int l, int r) {
    now = ++cnt;
    ls[now] = ls[pre];
    rs[now] = rs[pre];
    s[now] = s[pre] + val;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (k <= mid)
        init(k, val, ls[pre], ls[now], l, mid);
    else
        init(k, val, rs[pre], rs[now], mid + 1, r);
}

void build(int d, int pre, int now) {
    init(Hash(a[now]), 1, root[pre], root[now], 1, len);
    flag[now] = 1;
    ver[++cnt2] = now;
    first[now] = cnt2;
    R[cnt2] = d;
    fa[now] = pre;
    int l = v2[now].size();
    if (!l)
        return;
    for (int i = 0; i < l; i++) {
        if (flag[v2[now][i]])
            continue;
        build(d + 1, now, v2[now][i]);
        ver[++cnt2] = now, R[cnt2] = d;
    }
}

void ST(int n) {
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            int a = f[i][j - 1];
            int b = f[i + (1 << (j - 1))][j - 1];
            f[i][j] = R[a] < R[b] ? a : b;
        }
    }
}

int RMQ(int l, int r) {
    int k = log(r - l + 1) / log(2);
    int a = f[l][k], b = f[r - (1 << k) + 1][k];
    return R[a] < R[b] ? a : b;
}

int LCA(int l, int r) {
    int x = first[l];
    int y = first[r];
    if (x > y)
        swap(x, y);
    int res = RMQ(x, y);
    return ver[res];
}

int query(int l, int r, int k, int f) {
    int ll = 1, rr = len, cur = Hash(a[f]);
    l = root[l], r = root[r], f = root[f];
    while (ll <= rr) {
        if (ll == rr)
            return v[ll - 1];
        int m = (ll + rr) >> 1;
        int sum = s[ls[l]] + s[ls[r]] - 2 * s[ls[f]] + (cur <= m and cur >= ll ? 1 : 0);
        if (k <= sum) {
            rr = m;
            l = ls[l];
            r = ls[r];
            f = ls[f];
        } else {
            ll = m + 1;
            k -= sum;
            l = rs[l];
            r = rs[r];
            f = rs[f];
        }
    }
    return 0;
}
signed main() {
    int l, r, k;
    scanf("%lld%lld", &n, &m);
    v.clear();
    for (int i = 0; i <= n; i++) v2[i].clear();
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    memset(s, 0, sizeof(s));
    memset(root, 0, sizeof(root));
    cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    len = v.size();
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld", &l, &r);
        v2[l].push_back(r);
        v2[r].push_back(l);
    }

    cnt = 0;
    build(1, 0, 1);
    ST(cnt2);

    int last = 0;
    while (m--) {
        scanf("%lld%lld%lld", &l, &r, &k);
        l ^= last;
        printf("%lld\n", last = query(l, r, k, LCA(l, r)));
    }
}




#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 100005
#define int long long

int n, m, len, cnt, cnt2;
int root[maxn], ls[maxn << 5], rs[maxn << 5];
int a[maxn];
int s[maxn << 5];
int f[maxn << 1][20];
int R[maxn << 1];
int first[maxn], ver[maxn << 1], fa[maxn];
bool flag[maxn];

vector<int> v;
vector<int> v2[maxn];

int Hash(int k) { return lower_bound(v.begin(), v.end(), k) - v.begin() + 1; }

void init(int k, int val, int pre, int &now, int l, int r) {
    now = ++cnt;
    ls[now] = ls[pre];
    rs[now] = rs[pre];
    s[now] = s[pre] + val;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (k <= mid)
        init(k, val, ls[pre], ls[now], l, mid);
    else
        init(k, val, rs[pre], rs[now], mid + 1, r);
}

void build(int d, int pre, int now) {
    init(Hash(a[now]), 1, root[pre], root[now], 1, len);
    flag[now] = 1;
    ver[++cnt2] = now;
    first[now] = cnt2;
    R[cnt2] = d;
    fa[now] = pre;
    int l = v2[now].size();
    if (!l)
        return;
    for (int i = 0; i < l; i++) {
        if (flag[v2[now][i]])
            continue;
        build(d + 1, now, v2[now][i]);
        ver[++cnt2] = now, R[cnt2] = d;
    }
}

void ST(int n) {
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            int a = f[i][j - 1];
            int b = f[i + (1 << (j - 1))][j - 1];
            f[i][j] = R[a] < R[b] ? a : b;
        }
    }
}

int RMQ(int l, int r) {
    int k = log(r - l + 1) / log(2);
    int a = f[l][k], b = f[r - (1 << k) + 1][k];
    return R[a] < R[b] ? a : b;
}

int LCA(int l, int r) {
    int x = first[l];
    int y = first[r];
    if (x > y)
        swap(x, y);
    int res = RMQ(x, y);
    return ver[res];
}

int query(int l, int r, int k, int f) {
    int ll = 1, rr = len, cur = Hash(a[f]);
    l = root[l], r = root[r], f = root[f];
    while (ll <= rr) {
        if (ll == rr)
            return v[ll - 1];
        int m = (ll + rr) >> 1;
        int sum = s[ls[l]] + s[ls[r]] - 2 * s[ls[f]] + (cur <= m and cur >= ll ? 1 : 0);
        if (k <= sum) {
            rr = m;
            l = ls[l];
            r = ls[r];
            f = ls[f];
        } else {
            ll = m + 1;
            k -= sum;
            l = rs[l];
            r = rs[r];
            f = rs[f];
        }
    }
    return 0;
}
signed main() {
    int l, r, k;
    scanf("%lld%lld", &n, &m);
    v.clear();
    for (int i = 0; i <= n; i++) v2[i].clear();
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    memset(s, 0, sizeof(s));
    memset(root, 0, sizeof(root));
    cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    len = v.size();
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld", &l, &r);
        v2[l].push_back(r);
        v2[r].push_back(l);
    }

    cnt = 0;
    build(1, 0, 1);
    ST(cnt2);

    int last = 0;
    while (m--) {
        scanf("%lld%lld%lld", &l, &r, &k);
        l ^= last;
        printf("%lld\n", last = query(l, r, k, LCA(l, r)));
    }
}