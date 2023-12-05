#include <bits/stdc++.h>
using namespace std;
long long n, w, cnt1, cnt2;
long long ans, ans2;
long long u[50], v[50];
long long pre[2000010], pref[2000010];
string s[50];
struct node {
    long long u, v;
    long long f;
} a[2000010], b[2000010];
void dfs(int now, int end, long long mo, long long e, long long f, int opt) {
    if (now > end) {
        if (!opt)
            a[++cnt1].u = mo, a[cnt1].v = w - e, a[cnt1].f = f;
        else
            b[++cnt2].u = mo, b[cnt2].v = w - e, b[cnt2].f = f;
        if (e >= 0) {
            if (mo > ans) {
                ans = mo;
                ans2 = f;
            }
        }
        return;
    }
    dfs(now + 1, end, mo + u[now], e + v[now], f | (1ll << (now - 1ll)), opt);
    dfs(now + 1, end, mo, e, f, opt);
}
bool cmp(node a, node b) { return a.v < b.v; }
int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> u[i] >> v[i];
    }
    dfs(1, n / 2, 0, w, 0, 0);
    dfs(n / 2 + 1, n, 0, w, 0, 1);
    sort(a + 1, a + cnt1 + 1, cmp);
    sort(b + 1, b + cnt2 + 1, cmp);
    //	cout << cnt1 << " " << cnt2 << endl;
    //	for(int i = 1; i <= cnt2; i++) cout << b[i].u << " " << b[i].f << endl;
    pre[0] = -0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= cnt2; i++) {
        pre[i] = pre[i - 1], pref[i] = pref[i - 1];
        if (pre[i] < b[i].u)
            pre[i] = b[i].u, pref[i] = b[i].f;
    }
    for (int i = 1; i <= cnt1; i++) {
        long long l = 1, r = cnt2, w2 = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (b[mid].v <= w - a[i].v)
                w2 = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        //		cout << a[i].u << " " << a[i].v << " " << w2 << " " << b[w2].u << endl;
        if (a[i].u + pre[w2] > ans)
            ans = a[i].u + pre[w2], ans2 = a[i].f | pref[w2];
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if ((1ll << (i - 1ll)) & ans2)
            cout << s[i] << endl;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
long long n, w, cnt1, cnt2;
long long ans, ans2;
long long u[50], v[50];
long long pre[2000010], pref[2000010];
string s[50];
struct node {
    long long u, v;
    long long f;
} a[2000010], b[2000010];
void dfs(int now, int end, long long mo, long long e, long long f, int opt) {
    if (now > end) {
        if (!opt)
            a[++cnt1].u = mo, a[cnt1].v = w - e, a[cnt1].f = f;
        else
            b[++cnt2].u = mo, b[cnt2].v = w - e, b[cnt2].f = f;
        if (e >= 0) {
            if (mo > ans) {
                ans = mo;
                ans2 = f;
            }
        }
        return;
    }
    dfs(now + 1, end, mo + u[now], e + v[now], f | (1ll << (now - 1ll)), opt);
    dfs(now + 1, end, mo, e, f, opt);
}
bool cmp(node a, node b) { return a.v < b.v; }
int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> u[i] >> v[i];
    }
    dfs(1, n / 2, 0, w, 0, 0);
    dfs(n / 2 + 1, n, 0, w, 0, 1);
    sort(a + 1, a + cnt1 + 1, cmp);
    sort(b + 1, b + cnt2 + 1, cmp);
    //	cout << cnt1 << " " << cnt2 << endl;
    //	for(int i = 1; i <= cnt2; i++) cout << b[i].u << " " << b[i].f << endl;
    pre[0] = -0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= cnt2; i++) {
        pre[i] = pre[i - 1], pref[i] = pref[i - 1];
        if (pre[i] < b[i].u)
            pre[i] = b[i].u, pref[i] = b[i].f;
    }
    for (int i = 1; i <= cnt1; i++) {
        long long l = 1, r = cnt2, w2 = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (b[mid].v <= w - a[i].v)
                w2 = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        //		cout << a[i].u << " " << a[i].v << " " << w2 << " " << b[w2].u << endl;
        if (a[i].u + pre[w2] > ans)
            ans = a[i].u + pre[w2], ans2 = a[i].f | pref[w2];
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if ((1ll << (i - 1ll)) & ans2)
            cout << s[i] << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
long long n, w, cnt1, cnt2;
long long ans, ans2;
long long u[50], v[50];
long long pre[2000010], pref[2000010], pre2[2000010], pref2[2000010];
string s[50];
struct node {
    long long u, v;
    long long f;
} a[2000010], b[2000010];
void dfs(int now, int end, long long mo, long long e, long long f, int opt) {
    if (now > end) {
        if (!opt)
            a[++cnt1].u = mo, a[cnt1].v = w - e, a[cnt1].f = f;
        else
            b[++cnt2].u = mo, b[cnt2].v = w - e, b[cnt2].f = f;
        if (e >= 0) {
            if (mo > ans) {
                ans = mo;
                ans2 = f;
            }
        }
        return;
    }
    dfs(now + 1, end, mo + u[now], e + v[now], f | (1ll << (now - 1)), opt);
    dfs(now + 1, end, mo, e, f, opt);
}
bool cmp(node a, node b) { return a.v < b.v; }
int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> u[i] >> v[i];
    }
    dfs(1, n / 2, 0, w, 0, 0);
    dfs(n / 2 + 1, n, 0, w, 0, 1);
    sort(a + 1, a + cnt1 + 1, cmp);
    sort(b + 1, b + cnt2 + 1, cmp);
    //	cout << cnt1 << " " << cnt2 << endl;
    //	for(int i = 1; i <= cnt2; i++) cout << b[i].u << " " << b[i].f << endl;
    pre[0] = -0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= cnt2; i++) {
        pre[i] = pre[i - 1], pref[i] = pref[i - 1];
        if (pre[i] <= b[i].u)
            pre[i] = b[i].u, pref[i] = b[i].f;
    }
    pre2[0] = -0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= cnt1; i++) {
        pre2[i] = pre2[i - 1], pref2[i] = pref2[i - 1];
        if (pre2[i] <= a[i].u)
            pre2[i] = a[i].u, pref2[i] = a[i].f;
    }
    for (int i = 1; i <= cnt1; i++) {
        long long l = 1, r = cnt2, w2 = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (b[mid].v <= w - a[i].v)
                w2 = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        //		cout << a[i].u << " " << a[i].v << " " << w2 << " " << b[w2].u << endl;
        if (pre2[i] + pre[w2] >= ans)
            ans = pre2[i] + pre[w2], ans2 = pref2[i] | pref[w2];
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if ((ans2 >> (i - 1ll)) & 1ll)
            cout << s[i] << endl;
    }
    return 0;
}