#include <cstdio>
int dfs[1005][1005];
bool vis[1005];
long long ans = 0;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &dfs[i][j]);
      
  for (int i = n; i >= 1; i--) {
    vis[dfs[1][i]] = true;
    for (int j = 1; j <= n; j++) {
      if(!vis[dfs[dfs[1][i]][j]]) {
        ans += dfs[dfs[1][i]][j];
        break;
      }
    }
  }
  printf("%lld\n", ans + n * (n + 1) / 2 - 1);
  return 0;
}