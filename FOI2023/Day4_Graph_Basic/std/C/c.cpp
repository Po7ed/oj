#include <cstring>
#include <cstdio>
#include <algorithm>
int n, q, m, dp[201][201];
struct node {
    bool opt;
    int a, b, ans;
} qy[20050];
bool ib[205];
int main() {
    scanf("%d%d", &n, &m);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == b)
            continue;
        dp[a][b] = dp[b][a] = c;
    }
    scanf("%d", &q);
    int opt;
    for (int i = 1; i <= q; i++) {
        scanf("%d", &opt);
        if (opt == 1) {
            int a;
            scanf("%d", &a);
            qy[i] = (node){ false, a, 0 };
            ib[a] = true;
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            qy[i] = (node){ true, a, b };
        }
    }
    for (int k = n; k >= 1; k--)
        if (!ib[k]) {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++) dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    for (int i = q; i >= 1; i--) {
        if (qy[i].opt)
            qy[i].ans = dp[qy[i].a][qy[i].b];
        else {
            int k = qy[i].a;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++) dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
    for (int i = 1; i <= q; i++)
        if (qy[i].opt)
            printf("%d\n", qy[i].ans == 0x3f3f3f3f ? -1 : qy[i].ans);
    return 0;
}