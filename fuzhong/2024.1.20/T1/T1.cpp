#include <iostream>
using namespace std;

double c=0,tmp;

int main()
{
	// tmp=1;
	// for(int i=1;i<=61;i++)tmp+=(1.0/(i+1));
	// printf("%lf",tmp);
	scanf("%lf",&c);
	while(abs(c)>1e-10)
	{
		tmp=0;
		for(int i=1;i<=1145141;i++)
		{
			tmp+=(1.0/(i+1));
			if(tmp>=c){printf("%d\n",i);break;};
		}
		scanf("%lf",&c);
	}
	return 0;
}