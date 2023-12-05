#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(string x,string y)
{
	return (x+y>y+x);
}
int main()
{
	int n;
	scanf("%d",&n);
	string s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
		cout<<s[i];
	cout<<endl;
	return 0;
}