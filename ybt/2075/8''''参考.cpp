#include<bits/stdc++.h>
using namespace std;
struct cyy{
	int x,id;
}a[10010];
int n,q,d[10010];
bool cmp(cyy x,cyy y){//来呀排序呀 
	if(x.x!=y.x)return x.x<y.x;
	return x.id<y.id;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		d[a[i].id]=i;//存序号，d[i]是原来第i个现在的位置 
	int op,x,v;
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&v);
			a[d[x]].x=v;//修改 
			for(int j=n;j>=2;j--)
				if(cmp(a[j],a[j-1]))
					swap(a[j],a[j-1]);
			for(int j=2;j<=n;j++)
				if(cmp(a[j],a[j-1]))
					swap(a[j],a[j-1]);	
			for(int i=1;i<=n;i++)//更新 
				d[a[i].id]=i;
		}
		else{
			scanf("%d",&x);
			printf("%d\n",d[x]);
		} 
	}
	return 0;
}
————————————————
版权声明：本文为CSDN博主「c_yy_」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/c_yy_/article/details/121302950