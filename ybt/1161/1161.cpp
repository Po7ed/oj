#include <iostream>
using namespace std;

char transformationtable[]="0123456789ABCDEF";

void transformation(int x,int m)
{
	if(x==0)return;
	transformation(x/m,m);
	printf("%c",transformationtable[x%m]);
}

int main()
{
	int x,m;
	scanf("%d %d",&x,&m);
	if(x==0)puts("0");
	transformation(x,m);
	return 0;
}