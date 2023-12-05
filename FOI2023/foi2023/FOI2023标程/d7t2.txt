
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int pi[N];
char A[N];
bool vis[N];
int main() {
    memset(vis, true, sizeof(vis));
    scanf("%s", A);
    int len = strlen(A);
    for (int i = 1; i < len; i++) {
        int j = pi[i - 1];
        while (j > 0 && A[j] != A[i]) j = pi[j - 1];
        if (A[j] == A[i])
            j++;
        pi[i] = j;
        vis[j - 1] = false;
    }
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (vis[i])
            cnt++;
    printf("%d", cnt);
    // system("pause");
    return 0;
}

