#include <iostream>

/*
 * 先建树，节点中存两个值：最大值所在位置 ma，区间内满足的数量 cnt，比较时比比值，交叉相乘
 * 初始时叶子节点 ma=l=r，cnt=1
 * 考虑如何合并状态。clc(pre,pos) 表示计算 pos 对应区间，若前面有最大值 pre，答案为多少
 * 考虑合并，若为叶子，return [pre<a[ma]]
 * 否则若 pre>=a[ls.ma]，显然 ls 内被遮住，ls 贡献为 0，rs 贡献为 calc(pre,rs)
 * 反之，ls 贡献为 calc(pre,ls)，rs 贡献为 pos.cnt-ls.cnt，不是 rs.cnt 原因是后者未考虑 ls 内元素
 */

constexpr int N=114514;
typedef long long ll;
int n,m,h[N];

namespace sgt
{
	struct node{int ma,cnt,l,r;node():cnt(1){}};
	node t[N<<2];
	inline bool get(int x,int y){return (!x)?(!h[y]):(1ll*h[x]*y>=1ll*h[y]*x);}
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define L t[pos].l
	#define R t[pos].r
	#define mid ((L+R)>>1)
	int calc(int pos,int pre)
	{
		if(L==R)return !get(pre,t[pos].ma);
		if(get(pre,t[ls].ma))return calc(rs,pre);
		else return calc(ls,pre)+t[pos].cnt-t[ls].cnt;
	}
	inline void update(int pos)
	{
		t[pos].ma=get(t[ls].ma,t[rs].ma)?t[ls].ma:t[rs].ma;
		t[pos].cnt=t[ls].cnt+calc(rs,t[ls].ma);
	}
	void build(int pos=1,int l=1,int r=n)
	{
		L=l,R=r;
		if(L==R){t[pos].ma=l;return;}
		build(ls,l,mid),build(rs,mid+1,r);
		update(pos);
	}
	void modify(int mp,int mv,int pos=1)
	{
		if(L==R){h[mp]=mv;return;}
		if(mp<=mid)modify(mp,mv,ls);
		else modify(mp,mv,rs);
		update(pos);
	}
} // namespace sgt

int main()
{
	scanf("%d %d",&n,&m);
	sgt::build();
	int p,v;
	while(m--)
	{
		scanf("%d %d",&p,&v);
		sgt::modify(p,v);
		printf("%d\n",sgt::calc(1,0));
	}
	return 0;
}