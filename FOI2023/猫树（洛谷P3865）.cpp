#include <bits/stdc++.h>
using namespace std;
#define For(_,l,r) for(int _ = l; _ <= r; ++_)
#define _For(_,r,l) for(int _ = r; _ >= l; --_)
template <class R> inline bool Checkmax(R &A, R B) {
	return A < B ? A = B, 1 : 0;
}
template <class R> inline bool Checkmin(R &A, R B) {
	return A > B ? A = B, 1 : 0;
}
const int MaxLog = 17;
const int MaxN = 140000 + 10; // Greater than (1 << MaxLog) is enough
const int MaxM = 1000000 + 10;
int N, M, A[MaxN];
int T[MaxLog][MaxN]; // MAO Tree
int Log2[MaxN << 1]; // Careful here (MaxN << 1) and line 37 (N << 1)
// Pos(i) = id of tree node of A[i]
#define Pos(i) (i+N-1)
// Therefore, we do not care of tree node id during init
void Solve(int L, int R, int Dep) {
	if(L == R) return; // This is solved in line 42
	int Mid = (L + R) >> 1;
	T[Dep][Mid] = A[Mid];
	_For(i, Mid - 1, L) T[Dep][i] = max(T[Dep][i + 1], A[i]);
	T[Dep][Mid + 1] = A[Mid + 1];
	For(i, Mid + 2, R) T[Dep][i] = max(T[Dep][i - 1], A[i]);
	Solve(L, Mid, Dep + 1);
	Solve(Mid + 1, R, Dep + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	For(i, 1, N) cin >> A[i];
	N = 1 << MaxLog;
	For(i, 2, (N << 1)) Log2[i] = Log2[i >> 1] + 1;
	Solve(1, N, 0);
	while(M--) {
		int L, R;
		cin >> L >> R;
		if(L == R) cout << A[L] << '\n'; // Here
			else {
				int LCAdep = MaxLog - 1 - Log2[Pos(L) ^ Pos(R)];
				cout << max(T[LCAdep][L], T[LCAdep][R]) << '\n';
			}
	}
	return 0;
}
