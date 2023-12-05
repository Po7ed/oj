#include <bits/stdc++.h>
const int N = 2e5 + 5;

int n,m,c[N],fa[N],siz[N],cnt,p[N],ans;

bool s[N];

std::vector<int> a[N];

int Find(int x){
	if (x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}

void Union(int x,int y){
	x = Find(x),y = Find(y);
	if (x == y) return ;
	if (siz[x] < siz[y]) fa[x] = y, siz[y] += siz[x];
	else fa[y] = x, siz[x] += siz[y];
}

int max(int a,int b){
	return a > b ? a : b;
}

int main(){
	// freopen("slauqe.in","r",stdin); 
	// freopen("slauqe.out","w",stdout); 
	int k;
	scanf("%d %d %d",&n,&m,&k);
	for (int i = 1;i <= n;i++) fa[i] = i,siz[i] = 1;
	for (int i = 1;i <= n;i++) scanf("%d",&c[i]);
	// scanf("%d",&m);
	for (int i = 1;i <= m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		Union(l,r);
	}
	for (int i = 1;i <= n;i++){
		int Fa = Find(i);
		if (!s[Fa]) s[Fa] = 1, p[Fa] = ++cnt;
		a[p[Fa]].push_back(c[i]);
	}
	for (int i = 1;i <= cnt;i++){
		std::sort(a[i].begin(),a[i].end());
	}
	for (int i = 1;i <= cnt;i++){
		int ma = 0;
		for (int j = 0;j < (int)a[i].size();j++){
			int r = upper_bound(a[i].begin(),a[i].end(),a[i][j]) - a[i].begin(),l = lower_bound(a[i].begin(),a[i].end(),a[i][j]) - a[i].begin();
			ma = max(ma,r - l);
			j = r;
		}
		ans += a[i].size() - ma; 
	}
	printf("%d",ans);
}