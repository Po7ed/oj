#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	int l;
	int n,m;
	scanf("%d %d %d",&l,&n,&m);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int d[n+1];
	for(int i=1;i<n;i++)
		d[i]=a[i]-a[i-1];
	d[0]=a[0];
	d[n]=l-a[n-1];
	
	//for(int cm=0;cm<m;cm++)
	for(int cm=0;cm<m;cm++)
	{
		int minv=0x3f3f3f3f;
		int mini=0;
		for(int i=0;i<=n;i++)
			if(d[i]!=-1&&d[i]<minv)mini=i,minv=d[i];
		int l=1,r=1;
		while(d[mini-l]==-1&&mini-l!=-1)l++;
		while(d[mini+r]==-1&&mini+r!=n+1)r++;
		if(mini==0||mini-l==-1){
			d[mini+r]+=d[mini],d[mini]=-1;
			cout<<cm<<"/ ";
			for(int i=0;i<=n;i++)cout<<d[i]<<" ";
			puts("");
			/* cout<<mini+r<<"&"<<mini<<endl; */continue;}
		if(mini==n||mini+r==n+1){
			//d[mini-l]+=d[mini],d[mini]=-1;

			d[mini]+=d[mini-l],d[mini-l]=-1;

			cout<<cm<<"/ ";
			for(int i=0;i<=n;i++)cout<<d[i]<<" ";
			puts("");
			/* cout<<mini-l<<"&"<<mini<<endl; */continue;}
	//	if(d[mini-l]<d[mini+r]){d[mini-l]+=d[mini],d[mini]=-1;/* cout<<mini-l<<"&"<<mini<<endl; */}
		
		if(d[mini-l]<d[mini+r]){d[mini]+=d[mini-l],d[mini-l]=-1;/* cout<<mini-l<<"&"<<mini<<endl; */}
		
		else {d[mini+r]+=d[mini],d[mini]=-1;/* cout<<mini+r<<"&"<<mini<<endl; */}
		
		cout<<cm<<"/ ";
		for(int i=0;i<=n;i++)cout<<d[i]<<" ";
		puts("");
	}
	int minv=0x3f3f3f3f;

	for(int i=0;i<=n;i++)
		if(d[i]!=-1&&d[i]<minv)minv=d[i];
//for(int i=0;i<n;i++)cout<<i<<"*"<<d[i]<<" ";
	cout<<"****";
	for(int i=0;i<=n;i++){
		cout<<d[i]<<" ";

	}	
	puts("");
	printf("%d",minv);
	return 0;
}
