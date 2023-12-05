#include <iostream>
using namespace std;
int main()
{
	int k,m,n;//k falizhi; m jinengshu; n boss_tili
	scanf("%d %d %d",&k,&m,&n);
	int a,b;//a xiaohao; b shanghai
	bool nop=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		if(b==0)continue;
		if(a>k)continue;
		if(a==0){printf("%d ",i);continue;}
		if(n<=(b*(k/a))){printf("%d ",i);nop=0;}
	}
	if(nop)puts("-1");
	return 0;
}