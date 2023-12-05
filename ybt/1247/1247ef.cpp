#include <iostream>
using namespace std;
bool check(int a[],int mid,int p,int n,int l)
{
	int last=-1;
	while(p)
	{
		if(last==-1)
		{
			for(int i=0;i<n;i++)
				if(a[i]>=mid){p--;last=i;goto con;}
			// cout<<";check():false."<<endl;
			return 0;
		}
		else
		{
			for(int i=last;i<n;i++)
				if(a[i]-a[last]>=mid&&a[i]+mid<=l){p--;last=i;goto con;}
			// cout<<";check():false."<<endl;
			return 0;
		}
		con:continue;
	}
	if(l-a[last]>=mid)
	{
		// cout<<";check():ture"<<endl;
		return 1;
	}
	// cout<<";check():false."<<endl;
	return 0;
}
int main()
{
	// freopen("in.txt","r",stdin);
	int l,n,m;
	scanf("%d %d %d",&l,&n,&m);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int left=0,right=l;
	while(right-left!=1)
	{
		int mid=(right+left)/2;
		// cout<<"left:"<<left<<",right:"<<right<<",mid:"<<mid<<flush;
		if(check(a,mid,n-m,n,l))left=mid;
		else right=mid;
	}
	printf("%d",left);
	return 0;
}