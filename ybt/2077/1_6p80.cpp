#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void getfrt(int a[][3],int n)
{
	if(n==0)
		return;
	int kk=0;
	//int nn=0;// ��ǰ��������Ϊ0�ļ�¼�� 
	bool bf=1;

	for(int i=1;i<=n;i++)
	{
		if(a[i][0]!=a[i-1][0])
		{
			if(bf==0)
				printf(" ");
	 		printf("%d",a[i][1]);//�ȴ�ӡ������ 
			a[i][1]++;//������+1 
			a[i][2]--;//������ͬ����-1 
			bf=0;
		}
	
		if(a[i][2]!=0)// ������������1���� 
		{
		//	if(nn%2==0)//֮ǰ��������Ϊ0�ļ�¼Ϊż����0���������������
		//	{
				kk++;
				a[kk][0]=a[i][0];
				a[kk][1]=a[i][1];
				a[kk][2]=a[i][2];
			//	nn=0;
		//	}
		//	else a[kk][2]=a[kk][2]+ a[i][2];// ֮ǰ��������Ϊ0�ļ�¼Ϊ�������������������
		}	
	//	else nn++;	
	}
	printf("\n");
	getfrt(a,kk);
}

int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n+1][3];
	int k=1;
	int kk=1;
	a[0][0]=-1;////提前
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		a[i][1]=i;
	}
	for(int i=1;i<=n;i++)//��־��ͬ�� 
	{
		if(a[i][0]==a[i-1][0])
		{
			k++;
			a[i-k][2]++;
			a[i][2]=-1;//��ͬ��-1 
		}	
		else
		{
			k=0;
			a[i][2]=1;			
		}	
	}
	for(int i=1;i<=n;i++)// ѹ����ͬ�������������� 
	{
		if(a[i][2]!=-1)
		{
			a[kk][0]=a[i][0];
			a[kk][1]=a[i][1];
			a[kk][2]=a[i][2];
			kk++;
		}	
	}
	kk--;
/*or(int i=1;i<=kk;i++)
	{
		printf("%d,%d,%d",a[i][0],a[i][1],a[i][2]);
		puts("");
	}*/
	getfrt(a,kk);
	return 0;
}
