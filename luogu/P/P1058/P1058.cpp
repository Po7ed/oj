#include <iostream>
#include <string.h>
using namespace std;
const char blk[6][8]=
{
	"**+---+",
	"*/   /|",
	"+---+ |",
	"|   | +",
	"|   |/*",
	"+---+**"
};
char scr[1000][1000];
const int blkh=3,blkl=4,blkw=2;
int m,n;//m,i;n,j
int inf=0x3f3f3f3f;
int ib=inf,ie=-inf;//i=[ib,ie]
int jb=inf,je=-inf;
void print(int i,int j,int k)
{
	const int si=1+blkw*i+400,sj=1+blkl*j+400;
	// printf("%d %d\n",si,sj);
	for(int kk=0;kk<k;kk++)
	{
		for(int bi=0;bi<6;bi++)
		{
			for(int bj=0;bj<7;bj++)
			{
				if(blk[bi][bj]!='*')
				{
					scr[si+bi-kk*blkh][sj+bj-blkw*i]=blk[bi][bj];
					ib=min(ib,si+bi-kk*blkh);
					jb=min(jb,sj+bj-blkw*i);
					ie=max(ie,si+bi-kk*blkh);
					je=max(je,sj+bj-blkw*i);
				}
				if(scr[si+bi-kk*blkh][sj+bj-blkw*i]=='\0'&&blk[bi][bj]=='*')
				{
					scr[si+bi-kk*blkh][sj+bj-blkw*i]='.';
					ib=min(ib,si+bi-kk*blkh);
					jb=min(jb,sj+bj-blkw*i);
					ie=max(ie,si+bi-kk*blkh);
					je=max(je,sj+bj-blkw*i);
				}
			}
		}
	}
}

int main()
{
	memset(scr,0,sizeof(scr));
	int t,maxt=-1;
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&t);
			maxt=max(maxt,t);
			print(i,j,t);
		}
	}
	bool f=0;
	for(int i=ib;i<=ie;i++)
	{
		for(int j=jb;j<=je;j++)
		{
			if(scr[i][j]=='\0')
			{
				printf(".");
			}
			else
			{
				printf("%c",scr[i][j]);
			}
		}
		puts("");
	}
	return 0;
}