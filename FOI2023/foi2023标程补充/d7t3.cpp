#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    int res = 0;
    char c = getchar(), f = 1;
    while (c < 48 || c > 57) {
        if (c == '-')
            f = 0;
        c = getchar();
    }
    while (c >= 48 && c <= 57) res = (res << 3) + (res << 1) + (c & 15), c = getchar();
    return f ? res : -res;
}
inline void write(int x) {
    char c[21], len = 0;
    if (!x)
        return putchar('0'), void();
    if (x < 0)
        x = -x, putchar('-');
    while (x) c[++len] = x % 10, x /= 10;
    while (len) putchar(c[len--] + 48);
}
#define space(x) write(x), putchar(' ')

#define enter(x) write(x), putchar('\n')

const int N = 1e6 + 10;
char s[N];
struct trie {
    int c[N][26], tot, o;
    inline trie() { tot = 1; }
    inline void mov(char ch) { o = c[o][ch]; }
    inline void ins(char ch) {
        if (!c[o][ch])
            c[o][ch] = ++tot;
        mov(ch);
    }
} T1, T2;

typedef pair<int, int> pii;
vector<pii> qs[N];
void qry_init(int k) {
    scanf("%s", s);
    int len = strlen(s);
    T1.o = T2.o = 1;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '*')
            break;
        T1.mov(s[i] - 97);
        if (!T1.o)
            return;
    }
    for (int i = len - 1; ~i; --i) {
        if (s[i] == '*')
            break;
        T2.mov(s[i] - 97);
        if (!T2.o)
            return;
    }
    qs[T1.o].push_back(pii(k, T2.o));
}

struct BT {
    int n, c[N];
    inline void init(int N) { n = N; }
    inline void upd(int x, int y) {
        for (; x <= n; x += x & -x) c[x] += y;
    }
    inline int qry(int x) {
        int r = 0;
        for (; x; x -= x & -x) r += c[x];
        return r;
    }
} T;

int dfn[N], sz[N], id;
void dfs1(int u) {
    dfn[u] = ++id, sz[u] = 1;
    for (int i = 0; i < 26; ++i)
        if (T2.c[u][i])
            dfs1(T2.c[u][i]), sz[u] += sz[T2.c[u][i]];
}

int n, m, ans[N], ed[N];
void dfs2(int u) {
    if (ed[u])
        T.upd(dfn[ed[u]], 1);
    if (qs[u].size()) {
        for (int i = 0; i < qs[u].size(); ++i) {
            int k = qs[u][i].first, o = qs[u][i].second;
            ans[k] -= T.qry(dfn[o] + sz[o] - 1) - T.qry(dfn[o] - 1);
        }
    }
    for (int i = 0; i < 26; ++i)
        if (T1.c[u][i])
            dfs2(T1.c[u][i]);
    if (qs[u].size()) {
        for (int i = 0; i < qs[u].size(); ++i) {
            int k = qs[u][i].first, o = qs[u][i].second;
            ans[k] += T.qry(dfn[o] + sz[o] - 1) - T.qry(dfn[o] - 1);
        }
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        T1.o = T2.o = 1;
        int len = strlen(s);
        for (int i = 0; i < len; ++i) T1.ins(s[i] - 97), T2.ins(s[len - i - 1] - 97);
        ed[T1.o] = T2.o;
    }
    dfs1(1);
    for (int i = 1; i <= m; ++i) qry_init(i);
    T.init(T2.tot), dfs2(1);
    for (int i = 1; i <= m; ++i) enter(ans[i]);
}



