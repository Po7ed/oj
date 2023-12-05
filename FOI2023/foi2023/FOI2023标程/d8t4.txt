#include <bits/stdc++.h>
using namespace std;
#define maxn 50
#define int long long
int n, f[maxn][maxn][maxn], ans;
char s[maxn][maxn];
signed main() {
    freopen("division.in", "r", stdin);
    freopen("division.out", "w", stdout);
    scanf("%d", &n);
    assert(n >= 1 && n <= 20);
    n = n << 1;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        f[i][i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            assert(s[i][j] >= '0' && s[i][j] <= '1');
            assert(s[i][j] == s[j][i]);
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 2; (l + len - 1) <= n; l++) {
            int r = l + len - 1;
            for (int i = l + 1; i < r; i++) {
                for (int j = l; j < i; j++) {
                    for (int k = i + 1; k <= r; k++) {
                        if (s[j][k] == '0')
                            continue;
                        for (int p = j; p < i; p++) {
                            for (int q = i + 1; q <= k; q++) {
                                f[l][r][i] += f[l][p][j] * f[p + 1][q - 1][i] * f[q][r][k];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[1][i] == '1')
            ans += f[2][n][i];
    }
    printf("%lld", ans);
}





#include <bits/stdc++.h>
using namespace std;
#define maxn 50
#define int long long
int n, f[maxn][maxn][maxn], ans;
char s[maxn][maxn];
signed main() {
    freopen("division.in", "r", stdin);
    freopen("division.out", "w", stdout);
    scanf("%d", &n);
    assert(n >= 1 && n <= 20);
    n = n << 1;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        f[i][i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            assert(s[i][j] >= '0' && s[i][j] <= '1');
            assert(s[i][j] == s[j][i]);
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 2; (l + len - 1) <= n; l++) {
            int r = l + len - 1;
            for (int i = l + 1; i < r; i++) {
                for (int j = l; j < i; j++) {
                    for (int k = i + 1; k <= r; k++) {
                        if (s[j][k] == '0')
                            continue;
                        for (int p = j; p < i; p++) {
                            for (int q = i + 1; q <= k; q++) {
                                f[l][r][i] += f[l][p][j] * f[p + 1][q - 1][i] * f[q][r][k];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[1][i] == '1')
            ans += f[2][n][i];
    }
    printf("%lld", ans);
}


#include <bits/stdc++.h>

using namespace std;
#define maxn 50
#define int long long

int n, f[maxn][maxn][maxn], ans;
char s[maxn][maxn];

signed main() {
    freopen("division.in", "r", stdin);
    freopen("division.out", "w", stdout);
    scanf("%d", &n);
    n = n << 1;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        f[i][i][i] = 1;
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 2; (l + len - 1) <= n; l++) {
            int r = l + len - 1;
            for (int i = l + 1; i < r; i++) {
                for (int j = l; j < i; j++) {
                    for (int k = i + 1; k <= r; k++) {
                        if (s[j][k] == '0')
                            continue;
                        for (int p = j; p < i; p++) {
                            for (int q = i + 1; q <= k; q++) {
                                f[l][r][i] += f[l][p][j] * f[p + 1][q - 1][i] * f[q][r][k];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (s[1][i] == '1')
            ans += f[2][n][i];
    printf("%lld", ans);
}