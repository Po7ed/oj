#include <cstdio>
#include <cstring>
long long ansv;
int posx[1005], posy[1005];
int ans[1005], anscnt;
inline int abs(int a) {
  return a > 0 ? a : -a;
}
int getdist(int i, int j) {
  if (j < 0 || i < 0)
    return 0x7fffffff;
  return abs(posx[i] - posx[j]) + abs(posy[i] - posy[j]);
}

struct edge{
  int to, ne, w;
}e[2005];
int h[1005], cnt;
void add(int a, int b, int v) {
  e[++cnt] = (edge) {.to=b, .ne=h[a], .w=v}; h[a] = cnt;
  e[++cnt] = (edge) {.to=a, .ne=h[b], .w=v}; h[b] = cnt;
}

void dfs(int x, int fa) {
  if (fa != 0) ansv += getdist(ans[anscnt], x);
  ans[++anscnt] = x;
  for (int i = h[x]; i; i = e[i].ne) {
    if (e[i].to == fa) continue;
    dfs(e[i].to, x);
  }
}

int n, dis[1005], viscnt;
bool vis[1005];
void prim(int S) {
  vis[S] = true; viscnt = 1;
  for (int i = 1; i <= n; i++) dis[i] = S;
  dis[0] = -1;
  while (viscnt != n) {
    // find edge
    int nxt = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i] && getdist(dis[i], i) < getdist(dis[nxt], nxt)) nxt = i;
    // getedge
    viscnt++;
    add(nxt, dis[nxt], getdist(dis[nxt], nxt));
    vis[nxt] = true;
    // update
    for (int i = 1; i <= n; i++)
      if (!vis[i] && getdist(nxt, i) < getdist(dis[i], i)) dis[i] = nxt;
  }
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &posx[i], &posy[i]);
  prim(1);
  dfs(1, 0);
  printf("%lld\n", ansv + getdist(ans[1], ans[anscnt]));
  for (int i = 2; i <= anscnt; i++) {
    printf("%d ", ans[i]);
  }
  puts("");
  return 0;
}