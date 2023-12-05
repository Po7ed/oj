#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	if(x1==x2&&y1==y2)
	{
		puts("4");
		return 0;
	}
	if((abs(x1-x2)+abs(y1-y2))&1)
	{
		puts("-1");
		return 0;
	}
	else
	{
		if((abs(x1-x2)&1))
		{
			/* if(y1==y2)
			{
				printf("%d",abs(x1-x2)+abs(y1-y2));
			}
			else
			{ */
			if(x1<x2)
			{
				printf("%d",abs(x1-x2)+abs(y1-y2)+1);
				return 0;
			}
			else
			{
				printf("%d",abs(x1-x2)+abs(y1-y2)-1);
				return 0;
			}
			// }
			
		}
		else
		{
			printf("%d",abs(x1-x2)+abs(y1-y2));
			return 0;
		}
	}
	return 0;
}