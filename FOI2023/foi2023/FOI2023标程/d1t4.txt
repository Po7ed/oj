#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005];
bool check(long long x) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += min(x, a[i]);
    return sum / k >= x;
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long l = 0, r = 6e14, ans;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[500005];
bool check(long long mx) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += min(mx, a[i]);
    return sum / k >= mx;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    long long l = 0, r = 50000000000000000, ans = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    printf("%lld\n", ans);
}