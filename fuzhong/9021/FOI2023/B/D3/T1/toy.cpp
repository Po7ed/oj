#include <bits/stdc++.h>
using namespace std;
#define For(_,l,r) for(int _ = l; _ <= r; ++_)
const int MaxN = 540000 + 10;
struct things {
    // a：物品种类
	bool a;
    // b：容积/大小；Id：编号
	int b, Id;
	void In(int id) {
		cin >> a >> b;
		Id = id;
	}
} T[MaxN];
inline bool Cmp(things A, things B) {
	return A.b == B.b ? A.a > B.a : A.b < B.b;
}
inline bool Cmp2(things A, things B) {
	return A.Id < B.Id;
}
int N;
int Pos[MaxN];
// present[Nod]：以Nod为根的已匹配数量。
// toy[Nod]：以Nod为根的剩余玩具数量。
// box[Nod]：以Nod为根的剩余箱子数量。
int toy[MaxN], box[MaxN], present[MaxN];
#define Mid ((L + R) >> 1)
#define Ls (Nod << 1)
#define Rs (Nod << 1 | 1)
inline void Update(int Nod) {
	present[Nod] = present[Ls] + present[Rs] + min(toy[Ls], box[Rs]);
	toy[Nod] = toy[Rs] + max(0, toy[Ls] - box[Rs]);
	box[Nod] = box[Ls] + max(0, box[Rs] - toy[Ls]);
}
// Nod：当前线段树节点编号；L、R：Nod的区间范围；Pos：单点修改的编号（外）；Tag：物品类型
void Modify(int Nod, int L, int R, int Pos, bool Tag) {
	if(L == R) {// 找到了
		if(Tag) toy[Nod] = 1;
			else box[Nod] = 1;
	} else {
		if(Pos <= Mid) Modify(Ls, L, Mid, Pos, Tag);
			else Modify(Rs, Mid + 1, R, Pos, Tag);
		Update(Nod);// 更新
	}
}
int main() {
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	For(i, 1, N) T[i].In(i);
	sort(T + 1, T + 1 + N, Cmp);// 按大小排序
	For(i, 1, N) Pos[T[i].Id] = i;// 记录排序后的顺序
	sort(T + 1, T + 1 + N, Cmp2);// 排回去
	For(i, 1, N) {
		Modify(1, 1, N, Pos[i], T[i].a);
		cout << present[1] << endl;
	}
	return 0;
}