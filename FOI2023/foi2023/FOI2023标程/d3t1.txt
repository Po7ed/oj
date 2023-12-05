#include <bits/stdc++.h>
using namespace std;
long long pos[1145141], sum[1145141], lb[1145141], rb[1145141], n, q = 0;
struct sb {
    bool a;
    long long b, id;
} t[1145141];
bool cmp1(sb x, sb y) { return x.b == y.b ? x.a > y.a : x.b < y.b; }
bool cmp2(sb x, sb y) { return x.id < y.id; }
void up(long long nod) {
    sum[nod] = sum[nod << 1] + sum[nod << 1 | 1] + min(lb[nod << 1], rb[nod << 1 | 1]);
    lb[nod] = lb[nod << 1 | 1] + max(q, lb[nod << 1] - rb[nod << 1 | 1]);
    rb[nod] = rb[nod << 1] + max(q, rb[nod << 1 | 1] - lb[nod << 1]);
}
void m(long long nod, long long l, long long r, long long p, bool ta) {
    if (l == r) {
        if (ta) {
            lb[nod] = 1;
        } else {
            rb[nod] = 1;
        }
    } else {
        if (p <= ((l + r) >> 1)) {
            m((nod << 1), l, ((l + r) >> 1), p, ta);
        } else {
            m((nod << 1 | 1), ((l + r) >> 1) + 1, r, p, ta);
        }
        up(nod);
    }
}
int main() {
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> t[i].a >> t[i].b;
        t[i].id = i;
    }
    sort(t + 1, t + 1 + n, cmp1);
    for (long long i = 1; i <= n; i++) {
        pos[t[i].id] = i;
    }
    sort(t + 1, t + 1 + n, cmp2);
    for (long long i = 1; i <= n; i++) {
        m(1, 1, n, pos[i], t[i].a);
        cout << sum[1] << "\n";
    }
    return 114514;
}


#include <bits/stdc++.h>
using namespace std;
#define For(_, l, r) for (int _ = l; _ <= r; ++_)
const int MaxN = 540000 + 10;
struct things {
    bool a;
    int b, Id;
    void In(int id) {
        cin >> a >> b;
        Id = id;
    }
} T[MaxN];
inline bool Cmp(things A, things B) { return A.b == B.b ? A.a > B.a : A.b < B.b; }
inline bool Cmp2(things A, things B) { return A.Id < B.Id; }
int N;
int Pos[MaxN];
int Lb[MaxN], Rb[MaxN], Sum[MaxN];
#define Mid ((L + R) >> 1)
#define Ls (Nod << 1)
#define Rs (Nod << 1 | 1)
inline void Update(int Nod) {
    Sum[Nod] = Sum[Ls] + Sum[Rs] + min(Lb[Ls], Rb[Rs]);
    Lb[Nod] = Lb[Rs] + max(0, Lb[Ls] - Rb[Rs]);
    Rb[Nod] = Rb[Ls] + max(0, Rb[Rs] - Lb[Ls]);
}
void Modify(int Nod, int L, int R, int Pos, bool Tag) {
    if (L == R) {
        if (Tag)
            Lb[Nod] = 1;
        else
            Rb[Nod] = 1;
    } else {
        if (Pos <= Mid)
            Modify(Ls, L, Mid, Pos, Tag);
        else
            Modify(Rs, Mid + 1, R, Pos, Tag);
        Update(Nod);
    }
}
int main() {
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    For(i, 1, N) T[i].In(i);
    sort(T + 1, T + 1 + N, Cmp);
    For(i, 1, N) Pos[T[i].Id] = i;
    sort(T + 1, T + 1 + N, Cmp2);
    For(i, 1, N) {
        Modify(1, 1, N, Pos[i], T[i].a);
        cout << Sum[1] << endl;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define For(_, l, r) for (int _ = l; _ <= r; ++_)
const int MaxN = 540000 + 10;
struct things {
    bool a;
    int b, Id;
    void In(int id) {
        cin >> a >> b;
        Id = id;
    }
} T[MaxN];
inline bool Cmp(things A, things B) { return A.b == B.b ? A.a > B.a : A.b < B.b; }
inline bool Cmp2(things A, things B) { return A.Id < B.Id; }
int N;
int Pos[MaxN];
int Lb[MaxN], Rb[MaxN], Sum[MaxN];
#define Mid ((L + R) >> 1)
#define Ls (Nod << 1)
#define Rs (Nod << 1 | 1)
inline void Update(int Nod) {
    Sum[Nod] = Sum[Ls] + Sum[Rs] + min(Lb[Ls], Rb[Rs]);
    Lb[Nod] = Lb[Rs] + max(0, Lb[Ls] - Rb[Rs]);
    Rb[Nod] = Rb[Ls] + max(0, Rb[Rs] - Lb[Ls]);
}
void Modify(int Nod, int L, int R, int Pos, bool Tag) {
    if (L == R) {
        if (Tag)
            Lb[Nod] = 1;
        else
            Rb[Nod] = 1;
    } else {
        if (Pos <= Mid)
            Modify(Ls, L, Mid, Pos, Tag);
        else
            Modify(Rs, Mid + 1, R, Pos, Tag);
        Update(Nod);
    }
}
int main() {
    freopen("toy.in", "r", stdin);
    freopen("toy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    For(i, 1, N) T[i].In(i);
    sort(T + 1, T + 1 + N, Cmp);
    For(i, 1, N) Pos[T[i].Id] = i;
    sort(T + 1, T + 1 + N, Cmp2);
    For(i, 1, N) {
        Modify(1, 1, N, Pos[i], T[i].a);
        cout << Sum[1] << endl;
    }
    return 0;
}