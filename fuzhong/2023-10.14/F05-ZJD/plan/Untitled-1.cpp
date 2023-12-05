#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
long long a[MAXN];
long long b[MAXN],total;
int main(){
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) b[total++]=a[i]+i-1;
	sort(b,b+total);
	int siz=unique(b,b+total)-b;
	if(siz!=n) return !puts("orz");
	for(int i=0;i<n;i++) printf("%lld ",b[i]-i);
	return 0;
}