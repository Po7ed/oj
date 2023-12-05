#include <iostream>
using namespace std;

int log2(int n)
{
	if(n==0)return -1;
	else return log2(n/2)+1;
}

bool book=1;
void dfs(int n)
{
	bool book=1;
	if(n==0){return;}
	if(n==1){if(book){printf("2(0)");book=0;}else printf("+2(0)");return;}
	if(n==2){if(book){printf("2");book=0;}else printf("+2");return;}
	int x=1;
	while(x<=n)x*=2;x/=2;
	while(n!=0)
	{
		if(n<x){x/=2;continue;}
		n-=x;
		if(book)
		{
			if(x==2){printf("2");book=0;continue;}//免得显示"2(1)"
			if(x==1){printf("2(0)");book=0;continue;}//免得???????????????????????????????
		}
		if(x==2){printf("+2");continue;}//免得显示"2(1)"
		if(x==1){printf("+2(0)");continue;}//免得????????????????????????????
		if(book)
		{
			printf("2(");//移到里面,免得不需要打印"2("时打印
			book=0;
		}
		else
			printf("+2(");//移到里面,免得不需要打印"2("时打印
		dfs(log2(x));
		printf(")");//移到里面,免得不需要打印")"时打印
		x/=2;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	dfs(n);//n怎么表示？
	return 0;
}