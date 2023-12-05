#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	// scanf("%d",&n);
	cin>>n;
	string s[n+2];
	s[n+1]='-';
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	string t;
	cin>>t;
	sort(s+1,s+(n+1));
	string* p=lower_bound(s+1,s+(n+1),t);
	while(p->find(t)!=string::npos)
	{
		cout<<*p<<"\n";
		p++;
	}
	return 0;
}