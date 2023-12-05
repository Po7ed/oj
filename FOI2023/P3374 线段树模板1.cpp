#include <bits/stdc++.h>
#define For(_, L, R) for(int _ = L; _ <= R; ++_)
using namespace std;
const int MaxN = 1100000 + 10;
int N, M;
int A[MaxN], T[MaxN];
#define Ls (Nod<<1)
#define Rs (Nod<<1|1)
#define Mid (L+R>>1)
void Build(int Nod, int L, int R) {
	if(L == R) {
		T[Nod] = A[L];
		return;
	}
	Build(Ls, L, Mid);
	Build(Rs, Mid + 1, R);
	T[Nod] = T[Ls] + T[Rs];
}
void Modify(int Nod, int L, int R, int Pos, int K) {
	if(L == R) {
		T[Nod] += K;
		return;
	}
	if(Pos <= Mid) Modify(Ls, L, Mid, Pos, K);
		else Modify(Rs, Mid + 1, R, Pos, K);
	T[Nod] = T[Ls] + T[Rs];
}
int Query(int Nod, int L, int R, int Ql, int Qr) {
	if(L == Ql && R == Qr) return T[Nod];
	if(Qr <= Mid) return Query(Ls, L, Mid, Ql, Qr);
	if(Ql > Mid) return Query(Rs, Mid + 1, R, Ql, Qr);
	return Query(Ls, L, Mid, Ql, Mid) + Query(Rs, Mid + 1, R, Mid + 1, Qr);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	For(i, 1, N) cin >> A[i];
	Build(1, 1, N);
	For(i, 1, M) {
		int opt, x, y;
		cin >> opt >> x >> y;
		if(opt == 1) Modify(1, 1, N, x, y);
			else cout << Query(1, 1, N, x, y) << '\n';
	}
	return 0;
}

