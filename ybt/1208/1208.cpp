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
			if(x==2){printf("2");book=0;continue;}//�����ʾ"2(1)"
			if(x==1){printf("2(0)");book=0;continue;}//���???????????????????????????????
		}
		if(x==2){printf("+2");continue;}//�����ʾ"2(1)"
		if(x==1){printf("+2(0)");continue;}//���????????????????????????????
		if(book)
		{
			printf("2(");//�Ƶ�����,��ò���Ҫ��ӡ"2("ʱ��ӡ
			book=0;
		}
		else
			printf("+2(");//�Ƶ�����,��ò���Ҫ��ӡ"2("ʱ��ӡ
		dfs(log2(x));
		printf(")");//�Ƶ�����,��ò���Ҫ��ӡ")"ʱ��ӡ
		x/=2;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	dfs(n);//n��ô��ʾ��
	return 0;
}