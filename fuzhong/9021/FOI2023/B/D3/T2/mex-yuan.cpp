#include <bits/stdc++.h>
using namespace std;
#define For(_, l, r) for(int _ = l; _ <= r; ++_)
#define _For(_, r, l) for(int _ = r; _ >= l; --_)
const int MaxN = 1000000 + 10;
int N, A[MaxN], Mex[MaxN];
vector<int> Pos[MaxN];
bool Vis[MaxN];
int mex;
long long Sum[MaxN];
int Min[MaxN], Max[MaxN], Tag[MaxN];
#define Ls (Nod << 1)
#define Rs (Nod << 1 | 1)
#define Mid ((L + R) >> 1)
inline void Update(int Nod) {
	Sum[Nod] = Sum[Ls] + Sum[Rs];
	Min[Nod] = min(Min[Ls], Min[Rs]);
	Max[Nod] = max(Max[Ls], Max[Rs]);
}
void Build(int Nod, int L, int R) {
	Tag[Nod] = -1;
	if(L == R) Min[Nod] = Max[Nod] = Sum[Nod] = Mex[L];
		else {
			Build(Ls, L, Mid);
			Build(Rs, Mid + 1, R);
			Update(Nod);
		}
}
inline void Gettag(int Nod, int L, int R, int tag) {
	Min[Nod] = Max[Nod] = Tag[Nod] = tag;
	Sum[Nod] = 1ll * tag * (R - L + 1);
}
inline void Pushdown(int Nod, int L, int R) {
	if(Tag[Nod] != -1) {
		Gettag(Ls, L, Mid, Tag[Nod]);
		Gettag(Rs, Mid + 1, R, Tag[Nod]);
		Tag[Nod] = -1;
	}
}
void Modify(int Nod, int L, int R, int Ql, int Qr, int min) {
	if(L == Ql and R == Qr) {
		if(min >= Max[Nod]) return;
		if(min <= Min[Nod]) Gettag(Nod, L, R, min);
			else { // Only once in a query
				Pushdown(Nod, L, R);
				Modify(Ls, L, Mid, L, Mid, min);
				Modify(Rs, Mid + 1, R, Mid + 1, R, min);
				Update(Nod);
			}
	} else {
		Pushdown(Nod, L, R);
		if(Qr <= Mid) Modify(Ls, L, Mid, Ql, Qr, min);
		else if(Ql > Mid) Modify(Rs, Mid + 1, R, Ql, Qr, min);
		else Modify(Ls, L, Mid, Ql, Mid, min), Modify(Rs, Mid + 1, R, Mid + 1, Qr, min);
		Update(Nod);
	}
}
long long Query(int Nod, int L, int R, int Ql, int Qr) {
	if(L == Ql and R == Qr) return Sum[Nod];
	Pushdown(Nod, L, R);
	if(Qr <= Mid) return Query(Ls, L, Mid, Ql, Qr);
	if(Ql > Mid) return Query(Rs, Mid + 1, R, Ql, Qr);
	return Query(Ls, L, Mid, Ql, Mid) + Query(Rs, Mid + 1, R, Mid + 1, Qr);
} 
int main() {
	// freopen("mex.in", "r", stdin);
	// freopen("mex.out", "w", stdout);
	scanf("%d", &N);
	For(i, 1, N) scanf("%d", &A[i]);
	_For(i, N, 1) {
		Vis[A[i]] = true;
		while(Vis[mex]) ++mex;
		Mex[i] = mex;
	}
	Build(1, 1, N);
	For(i, 0, N) Pos[i].push_back(0);
	For(i, 1, N) Pos[A[i]].push_back(i);
	long long Ans = 0;
	_For(i, N, 1) {
		Ans += Query(1, 1, N, 1, i);
		Pos[A[i]].pop_back();
		int Last = Pos[A[i]].back();
		Modify(1, 1, N, Last + 1, i, A[i]);
	}
	printf("%lld\n", Ans);
	return 0;
}

