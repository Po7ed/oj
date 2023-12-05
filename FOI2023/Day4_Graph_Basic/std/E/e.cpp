#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
int read() {
    int f = 1;
    char ch = getchar();
    int res = 0;
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return f * res;
}

std::unordered_map<int, int> mx, my;
int T;
const int MaP = 2000005;
struct edge {
    int to, v, ne;
    edge(int _t = 0, int _v = 0, int _n = 0) : to(_t), v(_v), ne(_n) {}
} e[MaP * 2];
int h[MaP], cnt;
long long w[MaP];

void add(int a, int b, int v) {
    e[++cnt] = edge(b, v, h[a]);
    h[a] = cnt;
    e[++cnt] = edge(a, v, h[b]);
    h[b] = cnt;
    return;
}
bool vis[MaP];
int dep[MaP];
std::vector<int> blocks[MaP];
int ancst[MaP];

bool dfs(int x, int fa, int anc) {
    //	printf("%d\n",x);
    blocks[anc].push_back(x);
    vis[x] = true;
    for (int i = h[x]; i; i = e[i].ne) {
        if (e[i].to == fa)
            continue;
        int v = e[i].to;
        if (vis[v]) {
            if (w[x] + w[v] != e[i].v)
                return false;
        } else {
            w[v] = e[i].v - w[x];
            dep[v] = dep[x] + 1;
            if (!dfs(v, x, anc))
                return false;
        }
    }
    return true;
}
struct disnode {
    long long pos;
    int weight;
    disnode(long long _p = 0, int _w = 0) : pos(_p), weight(_w) {}
    bool operator<(const disnode &b) const { return pos < b.pos; }
} nowpos[MaP];
// #define POSTYPE 1
// #define NEGTYPE 0
inline long long myabs(long long x) { return x < 0 ? -x : x; }

int weight[MaP];
__int128 calans(int nowanc) {
    int nowposcon = 0;
    __int128 totans = 0;
    for (auto i : blocks[nowanc]) {
        if (dep[i] & 1)
            nowpos[nowposcon++] = disnode(w[i], weight[i]);
        else
            nowpos[nowposcon++] = disnode(-w[i], weight[i]);
    }

    std::sort(nowpos, nowpos + nowposcon);
    long long begin = nowpos[0].pos;
    for (int i = 0; i < nowposcon; i++) totans += nowpos[i].weight * myabs(begin - nowpos[i].pos);

    __int128 wholeweight = 0;
    for (int i = 1; i < nowposcon; i++) wholeweight -= nowpos[i].weight;
    wholeweight += nowpos[0].weight;

    for (int i = 1; i < nowposcon; i++) {
        if (wholeweight < 0) {
            totans += wholeweight * (nowpos[i].pos - nowpos[i - 1].pos);
            wholeweight += 2 * nowpos[i].weight;
        } else
            break;
    }

    return totans;
}

void init(int k) {
    mx.clear();
    my.clear();
    memset(h, 0, sizeof(h));
    memset(w, 0, sizeof(w));
    memset(vis, false, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    cnt = 0;
    for (int i = 0; i <= 2 * k; i++) blocks[i].clear();
    for (int i = 0; i <= 2 * k; i++) weight[i] = 1;
    return;
}
void print128(__int128 x) {
    if (x >= 10)
        print128(x / 10);
    putchar('0' + x % 10);
    return;
}
int main() {
    //	freopen("password12.in","r",stdin);
    T = read();
    while (T--) {
        int n, m, k;
        int stcnt = 0, ancstcon = 0;
        n = read();
        m = read();
        k = read();
        init(k);
        for (int i = 1; i <= k; i++) {
            int x, y, c;
            x = read();
            y = read();
            c = read();
            if (mx.find(x) == mx.end())
                mx[x] = ++stcnt;
            if (my.find(y) == my.end())
                my[y] = ++stcnt;
            add(mx[x], my[y], c);
        }
        int r, c;
        r = read();
        c = read();
        for (int i = 1; i <= r; i++) {
            int x;
            x = read();
            weight[mx[x]] = read();
        }
        for (int i = 1; i <= c; i++) {
            int y;
            y = read();
            weight[my[y]] = read();
        }

        bool flag = true;
        for (int i = 1; i <= stcnt; i++) {
            if (!vis[i]) {
                ancst[ancstcon++] = i;
                w[i] = dep[i] = 0;
                if (!dfs(i, 0, i)) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) {
            puts("-1");
            continue;
        }
        __int128 nowans = 0;
        for (int i = 0; i < ancstcon; i++) {
            int nowanc = ancst[i];
            nowans += calans(nowanc);
        }
        print128(nowans);
        putchar('\n');
    }
    return 0;
}