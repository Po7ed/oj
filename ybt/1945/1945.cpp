#include <iostream>
using namespace std;

int main()
{
	int n;
	bool bf=1;
	scanf("%d",&n);
	for(int i=n;i>=0;i--)
	{
		int t;
		scanf("%d",&t);
		if(t==0){continue;}
		else if(t==1&&i==1&&(!bf)){printf("+x");}
		else if(t==1&&i==1&&bf){printf("x");}
		else if(t==1&&i==0&&(!bf)){printf("+1");}
		else if(t==1&&i==0&&bf){printf("1");}
		else if(t==1&&(!bf)){printf("+x^%d",i);}
		else if(t==1&&bf){printf("x^%d",i);}
		else if(t==-1&&i==1){printf("-x");}
		else if(t==-1&&i==0){printf("-1");}
		else if(t==-1){printf("-x^%d",i);}
		else if(t>0&&i==1&&(!bf)){printf("+%dx",t);}
		else if(t>0&&i==1&&bf){printf("%dx",t);}
		else if(t>0&&i==0&&(!bf)){printf("+%d",t);}
		else if(t>0&&i==0&&bf){printf("%d",t);}
		else if(t>0&&(!bf)){printf("+%dx^%d",t,i);}
		else if(t>0&&bf){printf("%dx^%d",t,i);}
		else if(t<0&&i==1){printf("%dx",t);}
		else if(t<0&&i==0){printf("%d",t);}
		else {printf("%dx^%d",t,i);}
		bf=0;
	}
	return 0;
}