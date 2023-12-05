#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n+1];
	bool book=0,bf=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	do//果篮循环
	{
		bf=1;
		book=0;
		int t=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1||t==a[i])
				continue;
			else
			{
				t=a[i];
				//[1] a[i]=-1;
				if(bf==0)
					printf(" ");
				printf("%d",i);//[2]
				//[2] printf("%d",a[i]);
				a[i]=-1;//[1]
				bf=0;
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=-1)
				book=1;
		printf("\n");
	}
	while(book);
	system("pause");
	return 0;
}