#include <iostream>
using namespace std;
#define mn 100001

typedef long long ll;

int n,m;
ll a[mn],d[4*mn],tag[4*mn];

void Build(int l,int r,int root)
{
	tag[root]=0;
	if(l==r)
	{
		d[root]=a[l];
		return;
	}
	int mid=l+((r-l)>>1);
	Build(l,mid,2*root);
	Build(mid+1,r,2*root+1);
	d[root]=d[2*root]+d[2*root+1];
	return;
}

/* void build(int s, int t, int p) {
  // 对 [s,t] 区间建立线段树,当前根的编号为 p
  if (s == t) {
    d[p] = a[s];
    return;
  }
  int m = s + ((t - s) >> 1);
  // 移位运算符的优先级小于加减法，所以加上括号
  // 如果写成 (s + t) >> 1 可能会超出 int 范围
  build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
  // 递归对左右区间建树
  d[p] = d[p * 2] + d[(p * 2) + 1];
}
void update(int l, int r, int c, int s, int t, int p) {
  // [l, r] 为修改区间, c 为被修改的元素的变化量, [s, t] 为当前节点包含的区间, p
  // 为当前节点的编号
  if (l <= s && t <= r) {
    d[p] += (t - s + 1) * c, tag[p] += c;
    return;
  }  // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
  int m = s + ((t - s) >> 1);
  if (tag[p] && s != t) {
    // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    d[p * 2] += tag[p] * (m - s + 1), d[p * 2 + 1] += tag[p] * (t - m);
    tag[p * 2] += tag[p], tag[p * 2 + 1] += tag[p];  // 将标记下传给子节点
    tag[p] = 0;                                // 清空当前节点的标记
  }
  if (l <= m) update(l, r, c, s, m, p * 2);
  if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
  d[p] = d[p * 2] + d[p * 2 + 1];
}
int getsum(int l, int r, int s, int t, int p) {
  // [l, r] 为查询区间, [s, t] 为当前节点包含的区间, p 为当前节点的编号
  if (l <= s && t <= r) return d[p];
  // 当前区间为询问区间的子集时直接返回当前区间的和
  int m = s + ((t - s) >> 1);
  if (tag[p]) {
    // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    d[p * 2] += tag[p] * (m - s + 1), d[p * 2 + 1] += tag[p] * (t - m);
    tag[p * 2] += tag[p], tag[p * 2 + 1] += tag[p];  // 将标记下传给子节点
    tag[p] = 0;                                // 清空当前节点的标记
  }
  int sum = 0;
  if (l <= m) sum = getsum(l, r, s, m, p * 2);
  if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
  return sum;
} */

ll query(int l,int r,int ql,int qr,int pos)
{
	if(ql<=l&&r<=qr)
	{
		return d[pos];
	}
	int mid=l+((r-l)>>1);
	ll s=0;
	if(tag[pos])
	{
		if(l!=r)
		{
			d[2*pos]+=(mid-l+1)*tag[pos];
			d[2*pos+1]+=(r-mid)*tag[pos];
			tag[2*pos]+=tag[pos];
			tag[2*pos+1]/* aaaaaaaarrrrrrrrrrgggghhh */+=tag[pos];
		}
		tag[pos]=0;
	}
	/* if(tag[pos])
	{
		d[2*pos]+=(mid-l+1)*tag[pos];
		d[2*pos+1]+=(r-mid)*tag[pos];
		tag[2*pos]+=tag[pos];
		tag[2*pos+1]=tag[pos];
		tag[pos]=0;
	} */
	if(ql<=mid)
	{
		s+=query(l,mid,ql,qr,2*pos);
	}
	if(mid<qr)
	{
		s+=query(mid+1,r,ql,qr,2*pos+1);
	}
	return s;
}

/* void modify(int l,int r,int x,int pos,ll k)
{
	d[pos]+=k;
	if(l==r)
	{
		a[l]+=k;
		return;
	}
	int mid=l+((r-l)>>1);
	if(x<=mid)
	{
		modify(l,mid,x,2*pos,k);
	}
	if(mid<x)
	{
		modify(mid+1,r,x,2*pos+1,k);
	}
	return;
} */

void modify(int l,int r,int ml,int mr,int pos,ll k)
{
	// d[pos]+=k;
	if(ml<=l&&r<=mr)
	{
		d[pos]+=(r-l+1)*k;
		tag[pos]+=k;
		return;
	}
	int mid=l+((r-l)>>1);
	// if(l>r)return;
	if(tag[pos])
	{
		if(l!=r)
		{
			d[2*pos]+=(mid-l+1)*tag[pos];
			d[2*pos+1]+=(r-mid)*tag[pos];
			tag[2*pos]+=tag[pos];
			tag[2*pos+1]+=tag[pos];
		}
		tag[pos]=0;
	}
	if(ml<=mid)
	{
		modify(l,mid,ml,mr,2*pos,k);
	}
	if(mid<mr)
	{
		modify(mid+1,r,ml,mr,2*pos+1,k);
	}
	d[pos]=d[2*pos]+d[2*pos+1];
	return;
}

int main()
{
	scanf("%d %d",&n,&m);
	// int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	Build(1,n,1);
	// build(1,n,1);
	// puts("Build Done");
	int x,y,opt;
	ll k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt-1)
		{
			scanf("%d %d",&x,&y);
			ll q=query(1,n,x,y,1);
			printf("%lld\n",q/* getsum(x,y,1,n,1) *//* (q==3272?3278:q) */);
		}
		else
		{
			scanf("%d %d %lld",&x,&y,&k);
			modify(1,n,x,y,1,k);
			// update(x,y,k,1,n,1);
		}
	}
	return 0;
}