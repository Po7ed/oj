#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

char a[5][6];
#define d(i,j) abs(i-j)
#define t(i,j) (i*5+j)

int main()
{
	long long ans=0;
	scanf("%s\n%s\n%s\n%s\n%s",&a[0],&a[1],&a[2],&a[3],&a[4]);
	map<char,map<char,map<char,map<char,map<char,map<char,map<char,bool>>>>>>> vis;
	int H;
	int b[7];
	for(int i1=0;i1<5;i1++)
	for(int j1=0;j1<5;j1++)
	{
		for(int i2=0;i2<5;i2++)
		for(int j2=0;j2<5;j2++)
		{
			if(i1==i2&&j1==j2)
				continue;
			if(d(i1,i2)+d(j1,j2)!=1)
				continue;
			for(int i3=0;i3<5;i3++)
			for(int j3=0;j3<5;j3++)
			{
				if(i1==i3&&j1==j3||i2==i3&&j2==j3)
					continue;
				if(d(i1,i3)+d(j1,j3)!=1&&d(i2,i3)+d(j2,j3)!=1)
					continue;
				for(int i4=0;i4<5;i4++)
				for(int j4=0;j4<5;j4++)
				{
					if(i1==i4&&j1==j4||i2==i4&&j2==j4||i3==i4&&j3==j4)
						continue;
					if(d(i1,i4)+d(j1,j4)!=1&&d(i2,i4)+d(j2,j4)!=1&&d(i3,i4)+d(j3,j4)!=1)
						continue;
					for(int i5=0;i5<5;i5++)
					for(int j5=0;j5<5;j5++)
					{
						if(i1==i5&&j1==j5||i2==i5&&j2==j5||i3==i5&&j3==j5||i4==i5&&j4==j5)
							continue;
						if(d(i1,i5)+d(j1,j5)!=1&&d(i2,i5)+d(j2,j5)!=1&&d(i3,i5)+d(j3,j5)!=1&&d(i4,i5)+d(j4,j5)!=1)
							continue;
						for(int i6=0;i6<5;i6++)
						for(int j6=0;j6<5;j6++)
						{
							if(i1==i6&&j1==j6||i2==i6&&j2==j6||i3==i6&&j3==j6||i4==i6&&j4==j6||i5==i6&&j5==j6)
								continue;
							if(d(i1,i6)+d(j1,j6)!=1&&d(i2,i6)+d(j2,j6)!=1&&d(i3,i6)+d(j3,j6)!=1&&d(i4,i6)+d(j4,j6)!=1&&d(i5,i6)+d(j5,j6)!=1)
								continue;
							for(int i7=0;i7<5;i7++)
							for(int j7=0;j7<5;j7++)
							{
								if(d(i1,i7)+d(j1,j7)!=1&&d(i2,i7)+d(j2,j7)!=1&&d(i3,i7)+d(j3,j7)!=1&&d(i4,i7)+d(j4,j7)!=1&&d(i5,i7)+d(j5,j7)!=1&&d(i6,i7)+d(j6,j7)!=1)
									continue;
								if(i1==i7&&j1==j7||i2==i7&&j2==j7||i3==i7&&j3==j7||i4==i7&&j4==j7||i5==i7&&j5==j7||i6==i7&&j6==j7)
									continue;
								H=0;
								H+=(a[i1][j1]=='H'?1:0);
								H+=(a[i2][j2]=='H'?1:0);
								H+=(a[i3][j3]=='H'?1:0);
								H+=(a[i4][j4]=='H'?1:0);
								H+=(a[i5][j5]=='H'?1:0);
								H+=(a[i6][j6]=='H'?1:0);
								H+=(a[i7][j7]=='H'?1:0);
								if(H>3)
								{
									continue;
								}
								b[0]=t(i1,j1);
								b[1]=t(i2,j2);
								b[2]=t(i3,j3);
								b[3]=t(i4,j4);
								b[4]=t(i5,j5);
								b[5]=t(i6,j6);
								b[6]=t(i7,j7);
								sort(b,b+7);
								if(!vis[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]].count(b[6]))
								{
									vis[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]][b[6]]=true;
									ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
