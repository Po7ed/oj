#include<bits/stdc++.h>
using namespace std;
struct cyy{
	int x,id;
}a[10010];
int n,q,d[10010];
bool cmp(cyy x,cyy y){//��ѽ����ѽ 
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
		d[a[i].id]=i;//����ţ�d[i]��ԭ����i�����ڵ�λ�� 
	int op,x,v;
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&v);
			a[d[x]].x=v;//�޸� 
			for(int j=n;j>=2;j--)
				if(cmp(a[j],a[j-1]))
					swap(a[j],a[j-1]);
			for(int j=2;j<=n;j++)
				if(cmp(a[j],a[j-1]))
					swap(a[j],a[j-1]);	
			for(int i=1;i<=n;i++)//���� 
				d[a[i].id]=i;
		}
		else{
			scanf("%d",&x);
			printf("%d\n",d[x]);
		} 
	}
	return 0;
}
��������������������������������
��Ȩ����������ΪCSDN������c_yy_����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/c_yy_/article/details/121302950